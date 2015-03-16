#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace cv;
int main()
{
	namedWindow( "HSV", 1 );
	Mat img,hsv;
	img = imread("/home/marios/temp/ColorDetection/doll7.jpg");  //change this path according to your image file path
	//blur the image using GaussianBlur
	GaussianBlur( img, img, cv::Size(3,3), 0, 0, cv::BORDER_DEFAULT );
	cvtColor(img, hsv, CV_BGR2HSV);
	imshow("HSV",hsv);
	namedWindow( "Binary", 1 );
	Mat binary;
	inRange(hsv, Scalar(157, 72, 156), Scalar(180, 169, 255), binary);
	imshow("Binary",binary);
	//find contours from binary image
	int i;
	vector< vector<Point> > contours;
	findContours(binary, contours, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE); //find contours
	vector<double> areas(contours.size());
	//find largest contour area
	for(i = 0; i < contours.size(); i++)
	{
		areas[i] = contourArea(Mat(contours[i]));
	}
	//get index of largest contour
	double max;
	Point maxPosition;
	minMaxLoc(Mat(areas),0,&max,0,&maxPosition);
	//draw largest contour.
	drawContours(binary, contours, maxPosition.y, Scalar(255), CV_FILLED);
	imshow("LargestContour",binary);
	//draw bounding rectangle around largest contour
	Point center;
 	Rect r;
 	if (contours.size() >= 1)
	{
		r = boundingRect(contours[maxPosition.y]);
 		rectangle(img, r.tl(),r.br(), CV_RGB(255, 0, 0), 3, 8, 0); //draw rectangle
	}
 	//get centroid
 	center.x = r.x + (r.width/2);
	center.y= r.y + (r.height/2);
	//print x and y co-ordinates on image
	//char x[15],y[6];
	//std::string x = std::to_string(center.x);
    //std::string y = std::to_string(center.y);
	//itoa(center.x,x,10);
	//itoa(center.y,y,10);
	//strcat(x,",");
	//putText(img, strcat(x,y), center, FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(255,0,0), 1, CV_AA);
	imshow("Final",img);
    
    //wait for key press
	cvWaitKey();
	return 0;
	
}
