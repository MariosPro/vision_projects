#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>



/** @function main */
int main( )
{
  cv::Mat src= cv::Mat::zeros( 400, 400, CV_8UC1 );
  for (int j=200; j<203; j++)
  for (int i=200; i<300; i++)
  {
     src.at<uchar>(j,i)=255;

  }
  //src= cv::imread("squares.png");
  src=src(cv::Rect(199,199,5,5));
 
  cv::imshow("img",src);
  std::cout << "img = " << std::endl << " " << src << std::endl << std::endl;
  cv::Mat edges;
  Canny(src, edges, 0, 30, 3);
    cv::imshow("edges",edges);
  std::cout << "edges = " << std::endl << " " << edges << std::endl << std::endl;

  cv::waitKey(0);

  return 0;
}
