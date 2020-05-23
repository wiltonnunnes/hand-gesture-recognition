#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void func(Mat&, Mat&);

int main(){
  Mat frame, frame_threshold;
  VideoCapture cap;

  cap.open(0);
  if(!cap.isOpened()) {
    cerr << "ERROR! Unable to open camera\n";
    return -1;
  }

  for(;;) {
    cap.read(frame);
    if(frame.empty()) {
      cerr << "ERROR! blank frame grabbed\n";
      break;
    }

    func(frame, frame_threshold);
    imshow("Live", frame_threshold);
    if(waitKey(5) >= 0)
      break;
  }
  return 0;
}

void func(Mat& src, Mat& dst) {
  Mat src_HSV;
  cvtColor(src, src_HSV, COLOR_BGR2HSV);
  inRange(src_HSV, Scalar(110, 50, 50), Scalar(130, 255, 255), dst);
}