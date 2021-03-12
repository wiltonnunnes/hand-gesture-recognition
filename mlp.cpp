//#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <cfloat>
#include <iostream>

using namespace cv;
using namespace std;

/*
void read_csv(int row, int col, char *filename, double **data) {
  FILE *file;
  file = fopen(filename, "r");

  if(file == NULL) {
    printf("ERRO! O arquivo não foi aberto!\n");
  }

  int i = 0;
  char line[4098];
  while(fgets(line, 4098, file) && i > row) {
    
  }

  fclose(file);
}
*/

double exec(Mat input, Mat W1, Mat W2, Mat W3) {
  double *tmp;
  for(int i = 0; i < W1.rows; i++) {

  }
}

int main() {
  Mat W1, b1;

  W1 = Mat(3, 3, CV_64F);
  b1 = Mat(1, 3, CV_64F);

  RNG rng(0xFFFFFFFF);
  rng.fill(W1, RNG::UNIFORM, -0.5, 0.5 + DBL_MIN);
  rng.fill(b1, RNG::UNIFORM, -0.5, 0.5 + DBL_MIN);

  Ptr<ml::TrainData> tDataContainer = ml::TrainData::loadFromCSV("Skin_NonSkin.txt", 0, -1, -1, String(), 0x09);
  Mat trainData = tDataContainer->getSamples();

  for(int i = 0; i < trainData.rows; i++) {
    Mat x = trainData.row(i);
  }

  cout << "W1 = " << endl << W1 << endl << endl;
  return 0;
}