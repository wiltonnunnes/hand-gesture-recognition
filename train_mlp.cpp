#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
  Ptr<ml::TrainData> data = ml::TrainData::loadFromCSV("Skin_NonSkin.txt", 0, -1, -1, String(), 0x09);
  int nClasses = data->getResponses().cols;

  Mat layers = Mat(4, 1, CV_32S);

  layers.row(0) = data->getNVars();
  layers.row(1) = Scalar(3);
  layers.row(2) = Scalar(3);
  layers.row(3) = nClasses;

  Ptr<ml::ANN_MLP> mlp = ml::ANN_MLP::create();
  mlp->setLayerSizes(layers);

  mlp->setTrainMethod(ml::ANN_MLP::BACKPROP);
  mlp->setActivationFunction(ml::ANN_MLP::SIGMOID_SYM, 0, 0);
  mlp->setTermCriteria(TermCriteria(TermCriteria::EPS + TermCriteria::COUNT, 100000, 0.00001f));

  mlp->train(data);
  mlp->save("Skin_NonSkin_Model");
  return 0;
}