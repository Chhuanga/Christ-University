import cv2
import numpy as np
import subprocess
import threading
import time

# Define full paths to executables (CRITICAL: VERIFY THESE ARE CORRECT!)
PLUTOCAM_PATH = r"d:\drone\venv\scripts\plutocam.exe"
FFMPEG_PATH = r"C:\ffmpeg\bin\ffmpeg.exe"

# Haar Cascade Classifier for Face Detection
FACE_CASCADE_PATH = cv2.data.haarcascades + 'haarcascade_frontalface_default.xml'
face_cascade = cv2.CascadeClassifier(FACE_CASCADE_PATH)

if face_cascade.empty():
    print(f"Error: Could not load face cascade classifier from {FACE_CASCADE_PATH}.")
    exit()

# Create a separate thread for face detection to prevent blocking the main video loop
face_locations = []
current_frame = None
detection_ready = threading.Event()
processing_complete = threading.Event()
detection_active = True

def face_detection_worker():
    global face_locations, current_frame
    
    while detection_active:
        detection_ready.wait()  # Wait until a new frame is ready for processing
        
        if not detection_active:  # Check if we should exit
            break
            
        # Make a copy of the frame for processing
        frame_to_process = current_frame.copy()
        detection_ready.clear()  # Reset the event
        
        # Convert to grayscale and resize for faster processing
        gray = cv2.resize(cv2.cvtColor(frame_to_process, cv2.COLOR_BGR2GRAY), (160, 90))  # Even smaller for detection
        
        # Use aggressive parameters for faster detection
        faces = face_cascade.detectMultiScale(
            gray, 
            scaleFactor=1.4,     # More aggressive scaling (faster but less accurate)
            minNeighbors=3,      # Fewer neighbors required
            minSize=(30, 30),    # Smaller minimum face size
            maxSize=(80, 80),    # Smaller maximum face size
            flags=cv2.CASCADE_SCALE_IMAGE
        )
        
        # Scale the coordinates back to original frame size
        scale_factor_x = frame_width / 160
        scale_factor_y = frame_height / 90
        
        face_locations = []
        for (x, y, w, h) in faces:
            face_locations.append((
                int(x * scale_factor_x),
                int(y * scale_factor_y),
                int(w * scale_factor_x),
                int(h * scale_factor_y)
            ))
        
        processing_complete.set()  # Signal that processing is complete

# Start the face detection thread
detection_thread = threading.Thread(target=face_detection_worker)
detection_thread.daemon = True
detection_thread.start()

try:
    # Use string commands with shell=True
    process = subprocess.Popen(
        f'"{PLUTOCAM_PATH}" stream start --out-file -',
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        shell=True,
        bufsize=10485760  # 10MB buffer
    )
    
    # Use even lower resolution and faster conversion options in ffmpeg
    ffmpeg_process = subprocess.Popen(
        f'"{FFMPEG_PATH}" -i - -f rawvideo -pix_fmt bgr24 -vf scale=480:270 -',  # Reduced resolution
        stdin=process.stdout,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        shell=True,
        bufsize=10485760  # 10MB buffer
    )
    
    # Skip more frames to reduce processing load
    skip_frame_count = 0
    max_skip_frames = 2  # Process every third frame
    
    # Use a smaller frame size
    frame_width = 480   # Reduced from 640
    frame_height = 270  # Reduced from 360
    
    last_detection_time = time.time()
    detection_interval = 0.1  # Limit detection to 10 times per second
    
    while True:
        # Read the frame from ffmpeg output (smaller resolution)
        raw_frame = ffmpeg_process.stdout.read(frame_width * frame_height * 3)
        if not raw_frame:
            print("End of video stream or error in ffmpeg.")
            break
            
        # Skip frames to reduce processing load
        skip_frame_count += 1
        if skip_frame_count <= max_skip_frames:
            continue
        skip_frame_count = 0
            
        # Convert the byte data to a writeable numpy array (smaller resolution)
        frame = np.frombuffer(raw_frame, dtype=np.uint8).reshape((frame_height, frame_width, 3)).copy()
        
        # Only start new detection if enough time has passed and no detection is currently in progress
        current_time = time.time()
        if current_time - last_detection_time > detection_interval and not detection_ready.is_set():
            current_frame = frame.copy()
            last_detection_time = current_time
            detection_ready.set()  # Signal the detection thread

        # Draw rectangles for already detected faces
        for (x, y, w, h) in face_locations:
            cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 255, 0), 2)
        
        # Display the frame with face detections
        cv2.imshow('Video Stream with Face Detection', frame)
        
        # Exit loop if 'q' is pressed
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

except FileNotFoundError as e:
    print("Error: File not found. Ensure paths to plutocam and ffmpeg are correct.")
    print(e)
except Exception as e:
    print("An error occurred:", e)
    
finally:
    # Signal the detection thread to exit
    detection_active = False
    detection_ready.set()
    
    # Clean up: terminate the processes and close all OpenCV windows
    try:
        process.terminate()
        ffmpeg_process.terminate()
    except Exception as e:
        print("Error during termination:", e)
    
    cv2.destroyAllWindows()