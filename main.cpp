#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void func(Mat);

int main(){
  Mat frame, X;
  VideoCapture cap;
  Ptr<ml::ANN_MLP> model;

  cap.open(0);
  if(!cap.isOpened()) {
    cerr << "ERROR! Unable to open camera\n";
    return -1;
  }

  model->load("Skin_NonSkin_Model");

  for(;;) {
    cap.read(frame);
    if(frame.empty()) {
      cerr << "ERROR! blank frame grabbed\n";
      break;
    }

    frame.convertTo(X, CV_32FC3, 1 / 255);
    cout << "X = " << X << endl;

    //func(frame);
    imshow("Live", frame);
    if(waitKey(5) >= 0)
      break;
  }
  return 0;
}

void func(Mat src) {
  Mat src_HSV, dst, blurred;
  vector<vector<Point>> contours;
  vector<Vec4i> hierarchy;

  cvtColor(src, src_HSV, COLOR_BGR2HSV);
  inRange(src_HSV, Scalar(0, 59, 50), Scalar(25, 173, 255), dst);
  blur(dst, blurred, Size(3, 3));
  findContours(blurred, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
  drawContours(src, contours, -1, Scalar(0, 255, 0), 2, 8, hierarchy);
}