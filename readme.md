# Background Subtraction with Multiple Algorithms

This project demonstrates background subtraction on a video file using multiple algorithms in OpenCV. Background subtraction is a technique in computer vision used to detect moving objects in a video by comparing each frame to a background model.

## Overview

The project processes a video (`video2.avi`) and applies various background subtraction techniques to identify foreground objects. Different algorithms are implemented, each providing unique methods to model the background and detect changes in the scene.

## Algorithms

This application includes the following background subtraction algorithms:

1. **FrameDifferenceBGS**: Simple frame differencing to detect sudden changes.
2. **StaticFrameDifferenceBGS**: Uses a static frame for background comparison, suitable for stationary backgrounds.
3. **AdaptiveBackgroundLearning**: Gradually adapts the background using an `alpha` parameter, making it more resilient to environmental changes.
4. **DPZivkovicAGMMBGS**: Uses an adaptive Gaussian Mixture Model (GMM) to model complex backgrounds.
5. **FuzzyChoquetIntegral**: Employs fuzzy logic to evaluate texture and color similarity for complex texture-based background modeling.

## Requirements

- OpenCV (version 2.4.3 or higher recommended for compatibility with the GMG algorithm)
- C++ Compiler

## How It Works

1. **Video Input**: The application reads frames from `video2.avi`.
2. **Background Modeling**: The selected algorithm creates or updates the background model based on each frame.
3. **Foreground Detection**: The difference between the current frame and the background model is used to detect foreground objects.
4. **Display**: The original frame, background model, and foreground mask are displayed in real-time.

## Setup

1. Clone the repository.
   ```bash
   git clone [your-repo-url]
   cd [repo-folder]
   ```

## Compilation and Execution

1. **Compile the project** using your preferred C++ compiler and OpenCV.

2. **Run the application**:
   ```bash
   ./your_compiled_program
   ```

## Usage

- The application will display the input video, background model, and foreground mask.
- Press **'q'** to exit the application.

## File Structure

- **main.cpp**: The main application file that sets up video input and selects the background subtraction method.
- **adaptiveGMM.cpp**: Implements the DP Zivkovic Adaptive GMM algorithm.
- **adbGlearning.cpp**: Implements the Adaptive Background Learning algorithm.
- **fuzzyintegral.cpp**: Implements the Fuzzy Choquet Integral-based background subtraction.

## Notes

- The program defaults to the `FuzzyChoquetIntegral` algorithm as it’s the last assigned method in `main.cpp`.
- Ensure `video2.avi` is available in the dataset folder, or modify the video path in `main.cpp` if needed.
