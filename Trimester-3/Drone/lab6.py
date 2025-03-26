import cv2  
import numpy as np
import subprocess

# Define full paths to executables
PLUTOCAM_PATH = r"d:\drone\venv\scripts\plutocam.exe"  # Adjust this if needed
FFMPEG_PATH = "C:\\ffmpeg\\bin\\ffmpeg.exe"


try:
    # Start the drone video stream and set up ffmpeg to convert the video stream
    process = subprocess.Popen(
        [PLUTOCAM_PATH, "stream", "start", "--out-file", "-"],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,  # Capture errors
        shell=True  # Required on Windows for some commands
    )

    ffmpeg_process = subprocess.Popen(
        [FFMPEG_PATH, "-i", "-", "-f", "rawvideo", "-pix_fmt", "bgr24", "-"],
        stdin=process.stdout,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,  # Capture errors
        shell=True
    )

    while True:
        # Read the frame from ffmpeg output
        raw_frame = ffmpeg_process.stdout.read(2048 * 1152 * 3)  # Adjust resolution
        if not raw_frame:
            break

        # Convert the byte data to a numpy array
        frame = np.frombuffer(raw_frame, dtype=np.uint8).reshape((1152, 2048, 3))

        # Display the frame using OpenCV
        cv2.imshow('Video Stream', frame)

        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

except FileNotFoundError as e:
    print("Error: File not found. Ensure paths to plutocam and ffmpeg are correct.")
    print(e)
except Exception as e:
    print("An error occurred:", e)

finally:
    # Clean up: terminate the process and close all OpenCV windows
    process.terminate()
    ffmpeg_process.terminate()
    cv2.destroyAllWindows()