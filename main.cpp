#include <iostream>
//#include <opencv2/opencv.hpp>
#include <cv.h>
#include <highgui.h>

#include "package_bgs/FrameDifferenceBGS.h"
#include "package_bgs/StaticFrameDifferenceBGS.h"

#include "package_bgs/AdaptiveBackgroundLearning.h"

#if CV_MAJOR_VERSION >= 2 && CV_MINOR_VERSION >= 4 && CV_SUBMINOR_VERSION >= 3
#include "package_bgs/GMG.h"
#endif

#include "package_bgs/dp/DPZivkovicAGMMBGS.h"

#include "package_bgs/tb/FuzzyChoquetIntegral.h"


int main(int argc, char **argv)
{
  std::cout << "Using OpenCV " << CV_MAJOR_VERSION << "." << CV_MINOR_VERSION << "." << CV_SUBMINOR_VERSION << std::endl;

  /* Open video file */
  CvCapture *capture = 0;

  capture = cvCaptureFromAVI("dataset/video2.avi");


  if (!capture)
  {
	  std::cerr << "Cannot open video!" << std::endl;
	  return -1;
  }
  

  /* Background Subtraction Methods */
  IBGS *bgs;

  /*** Default Package ***/
  //bgs = new FrameDifferenceBGS;
  //bgs = new StaticFrameDifferenceBGS;

  bgs = new AdaptiveBackgroundLearning;
  
  bgs = new DPZivkovicAGMMBGS;

  bgs = new FuzzyChoquetIntegral;

  std::cout << "Press 'q' to quit..." << std::endl;
  int key = 0;
  IplImage *frame;
  while (key != 'q')
  {
	  frame = cvQueryFrame(capture);
	  if (!frame) break;

	  cv::Mat img_input(frame);
	  cv::imshow("Input", img_input);

	  // bgs->process(...) internally process and show the foreground mask image
	  cv::Mat img_bkgmodel;
	  cv::Mat img_mask;
	  bgs->process(img_input, img_mask, img_bkgmodel);

	  key = cvWaitKey(1);

  }
    //if(!img_mask.empty())
    //  cv::imshow("Foreground", img_mask);
    //  do something
    

  delete bgs;

  cvDestroyAllWindows();
  cvReleaseCapture(&capture);

  return 0;
}
