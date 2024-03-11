/**
 * @file Drawing_2.cpp
 * @brief Simple sample code
 */

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace cv;
using namespace std;

void noRed(string filename){
  Mat image = imread(filename);
  vector<cv::Mat> channels;
  cv::split(image,channels);
  channels[2] = cv::Mat::zeros(image.rows,image.cols,CV_8UC1);

  cv::Mat result;
  cv::merge(channels,result);

  cv::imshow("Original Image", image);
  cv::imshow("Image with Red Removed", result);
  cv::waitKey(0);
}

void noBlue(string filename){
  Mat image = imread(filename);
  vector<cv::Mat> channels;
  cv::split(image,channels);
  channels[0] = cv::Mat::zeros(image.rows,image.cols,CV_8UC1);

  cv::Mat result;
  cv::merge(channels,result);

  cv::imshow("Original Image", image);
  cv::imshow("Image with Red Removed", result);
  cv::waitKey(0);
}

void noGreen(string filename){
  Mat image = imread(filename);
  vector<cv::Mat> channels;
  cv::split(image,channels);
  channels[1] = cv::Mat::zeros(image.rows,image.cols,CV_8UC1);

  cv::Mat result;
  cv::merge(channels,result);

  cv::imshow("Original Image", image);
  cv::imshow("Image with Red Removed", result);
  cv::waitKey(0);
}

void grayscale(string filename){
  Mat image = imread(filename);
  cv::Mat grayImage;
  cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);

  cv::imshow("Original Image", image);
  cv::imshow("Image with Red Removed", grayImage);
  cv::waitKey(0);
}

void inverted(string filename){
  Mat image = imread(filename);
  cv::Mat invertedImage = cv::Scalar(255, 255, 255) - image;

  cv::imshow("Original Image", image);
  cv::imshow("Image with Red Removed", invertedImage);
  cv::waitKey(0);
}

void flipVertically(string filename){
  Mat image = imread(filename);
  cv::Mat flippedImage;
  cv::flip(image, flippedImage, 0); // 0 for vertical flip

  cv::imshow("Original Image", image);
  cv::imshow("Image with Red Removed", flippedImage);
  cv::waitKey(0);
}

void flipHorizontally(string filename){
  Mat image = imread(filename);
  cv::Mat flippedImage;
  cv::flip(image, flippedImage, 1);

  cv::imshow("Original Image", image);
  cv::imshow("Image with Red Removed", flippedImage);
  cv::waitKey(0);
}
int main(int argc, char** argv) {
    string file_name, instruction, new_image;

    file_name = argv[1];
   if (argc==4){
        file_name = argv[1];
        instruction = argv[2];
        new_image = argv[3];
   } else if (argc<4){
    cout<<"Too few arguments."<<endl;
	cout<<"Usage: ./main <path to file> <filter> <new file name>"<<endl;
   } else{
    cout<<"Too many arguments"<<endl;
	cout<<"Usage: ./main <path to file> <filter> <new file name>"<<endl;
   }


  
  if(instruction=="noRed"){
    noRed(file_name);
  } else if(instruction=="noGreen"){
    noGreen(file_name);
  } else if(instruction=="noBlue"){
    noBlue(file_name);
  } else if(instruction=="invert"){
    inverted(file_name);
  }  else if(instruction=="grayscale"){
    grayscale(file_name);
  } else if(instruction=="flipHorizontally"){
    flipHorizontally(file_name);
  }  else if(instruction=="flipVertically"){
    flipVertically(file_name);  }
  else {
    cout<<"wrong instruction given"<<endl;
	cout<<"Usage: ./main <path to file> <filter> <new file name>"<<endl;
  }


  return 0;
}