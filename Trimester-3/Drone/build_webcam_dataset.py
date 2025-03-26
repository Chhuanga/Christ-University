import cv2
import os
import time
import argparse

# Parse command line arguments
parser = argparse.ArgumentParser(description='Build a face dataset using the default webcam')
parser.add_argument('--name', '-n', required=True, help='Name of the person (use underscores for spaces)')
parser.add_argument('--count', '-c', type=int, default=50, help='Number of images to capture (default: 50)')
parser.add_argument('--interval', '-i', type=float, default=0.5, help='Interval between captures in seconds (default: 0.5)')
args = parser.parse_args()

# Create directory for known faces
person_name = args.name.replace('_', ' ').title()
known_faces_dir = os.path.join(os.path.dirname(__file__), "KnownFaces")
if not os.path.exists(known_faces_dir):
    os.makedirs(known_faces_dir)
    print(f"Created directory for known faces: {known_faces_dir}")

dataset_dir = os.path.join(known_faces_dir, args.name)
if not os.path.exists(dataset_dir):
    os.makedirs(dataset_dir)
    print(f"Created directory for {person_name}: {dataset_dir}")

# Variables for image capture
capture_count = 0
max_captures = args.count
last_capture_time = 0
capture_interval = args.interval

# Haar Cascade Classifier for Face Detection
face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

if face_cascade.empty():
    print("Error: Could not load face cascade classifier.")
    exit()

# Initialize the webcam
print("Initializing webcam...")
cap = cv2.VideoCapture(1)

# Check if webcam opened successfully
if not cap.isOpened():
    print("Error: Could not open webcam.")
    exit()

# Get the webcam's resolution
frame_width = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
frame_height = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
print(f"Webcam resolution: {frame_width}x{frame_height}")

print(f"Starting dataset creation for: {person_name}")
print(f"Will capture {max_captures} images with {capture_interval} second intervals")
print("Position your face in the camera frame and stay relatively still")
print("Press 'q' to quit early, press 's' to start capturing")

# Wait for user to press 's' to start
capturing = False

try:
    while True:
        # Capture frame from webcam
        ret, frame = cap.read()
        
        if not ret:
            print("Error: Failed to capture frame from webcam.")
            break
        
        # Convert to grayscale for face detection
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        
        # Detect faces
        faces = face_cascade.detectMultiScale(
            gray, 
            scaleFactor=1.1,
            minNeighbors=5,
            minSize=(30, 30),
            flags=cv2.CASCADE_SCALE_IMAGE
        )
        
        # Draw rectangles around faces
        largest_face = None
        largest_area = 0
        
        for (x, y, w, h) in faces:
            cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 255, 0), 2)
            
            # Track the largest face (likely the closest/main subject)
            area = w * h
            if area > largest_area:
                largest_area = area
                largest_face = (x, y, w, h)
        
        # Display status information
        if not capturing:
            cv2.putText(frame, "Press 's' to start capturing", (20, 30), 
                        cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)
        else:
            cv2.putText(frame, f"Capturing: {capture_count}/{max_captures}", (20, 30), 
                        cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)
            
            # Show countdown to next capture
            remaining = capture_interval - (time.time() - last_capture_time)
            if remaining > 0:
                cv2.putText(frame, f"Next capture in: {remaining:.1f}s", (20, 60), 
                            cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)
        
        # Display if face is detected
        if len(faces) == 0:
            cv2.putText(frame, "No face detected", (20, 90), 
                        cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 255), 2)
        
        # Display the frame
        cv2.imshow('Face Dataset Builder', frame)
        
        # Capture images when in capturing mode and a face is detected
        if capturing and largest_face and capture_count < max_captures:
            current_time = time.time()
            if current_time - last_capture_time > capture_interval:
                # Extract just the face region with some margin
                x, y, w, h = largest_face
                
                # Add a margin around the face (20% of dimensions)
                margin_x = int(w * 0.2)
                margin_y = int(h * 0.2)
                
                # Ensure we don't go out of bounds
                x1 = max(0, x - margin_x)
                y1 = max(0, y - margin_y)
                x2 = min(frame_width, x + w + margin_x)
                y2 = min(frame_height, y + h + margin_y)
                
                # Extract the face region
                face_img = frame[y1:y2, x1:x2]
                
                # Save the face image with timestamp
                timestamp = time.strftime("%Y%m%d_%H%M%S")
                img_name = f"{args.name}_{timestamp}_{capture_count+1}.jpg"
                img_path = os.path.join(dataset_dir, img_name)
                
                if face_img.size > 0:  # Make sure we have a valid image
                    cv2.imwrite(img_path, face_img)
                    capture_count += 1
                    last_capture_time = current_time
                    print(f"Image {capture_count}/{max_captures} saved to {img_path}")
        
        # Check for key presses
        key = cv2.waitKey(1) & 0xFF
        
        # Start capturing if 's' is pressed
        if key == ord('s') and not capturing:
            capturing = True
            last_capture_time = time.time()
            print("Starting capture sequence...")
            
        # Exit if 'q' is pressed or we've captured enough images
        if key == ord('q') or capture_count >= max_captures:
            break

except Exception as e:
    print(f"An error occurred: {e}")
    
finally:
    # Clean up
    cap.release()
    cv2.destroyAllWindows()
    
    # Final status
    if capture_count > 0:
        print(f"\nDataset creation complete!")
        print(f"Captured {capture_count} images for {person_name}")
        print(f"Images saved to: {dataset_dir}")
        print("\nYou can now use this dataset with your face recognition system.")
    else:
        print("\nNo images were captured. Please try again.")