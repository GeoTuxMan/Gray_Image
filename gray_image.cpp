#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "opencv2/core/core.hpp"
#include <stdio.h>

using namespace cv;
using namespace std;


// convert color image to gray image
//compile: g++ -Wall -o gray_image gray_image.cpp `pkg-config --cflags --libs opencv`
// run: gray_image motan.jpg
int main(int argc, char** argv)
{
char* imageName = argv[1]; //image name need to be input at run
Mat image;
image = imread(imageName, 1);

if(argc != 2 || !image.data)
{
cout<<"No image data \n";
return -1;
}

Mat gray_image;
cvtColor(image, gray_image, CV_BGR2GRAY);
imwrite("/home/george/Desktop/gray_image/GrayImage.jpg", gray_image);
namedWindow(imageName, CV_WINDOW_AUTOSIZE);
namedWindow("Gray Image", CV_WINDOW_AUTOSIZE);
imshow(imageName, image); //color image
imshow("Gray Image", gray_image); //gray image

waitKey(0);
return 0;
}
