#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>



/** @function main */
int main( )
{

  cv::Mat src_gray;
  cv::Mat grad;
  cv::Mat edges;
  //char* window_name = "Sobel Demo - Simple Edge Detector";
  int scale = 1;
  int delta = 0;
  int ddepth = CV_16S;

  int c;
  cv::VideoCapture cap(0);
  if (!cap.isOpened())
  {
	  return -1;
  } 
  while(1)
	{
		 cv::Mat src;
		cap.grab();
		cap.retrieve(src);
	  GaussianBlur( src, src, cv::Size(3,3), 0, 0, cv::BORDER_DEFAULT );

	  /// Convert it to gray
	  cvtColor( src, src_gray, CV_RGB2GRAY );
	  edges=src_gray;

	  /// Create window
	  //namedWindow( window_name, CV_WINDOW_AUTOSIZE );

	  /// Generate grad_x and grad_y
	  cv::Mat grad_x, grad_y;
	  cv::Mat abs_grad_x, abs_grad_y;

	  /// Gradient X
	  //Scharr( src_gray, grad_x, ddepth, 1, 0, scale, delta, BORDER_DEFAULT );
	  Sobel( src_gray, grad_x, ddepth, 1, 0, 3, scale, delta, cv::BORDER_DEFAULT );
	  convertScaleAbs( grad_x, abs_grad_x );

	  /// Gradient Y
	  //Scharr( src_gray, grad_y, ddepth, 0, 1, scale, delta, BORDER_DEFAULT );
	  Sobel( src_gray, grad_y, ddepth, 0, 1, 3, scale, delta, cv::BORDER_DEFAULT );
	  convertScaleAbs( grad_y, abs_grad_y );

	  /// Total Gradient (approximate)
	  addWeighted( abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad );
    std::cout << "grad = " << std::endl << " " << grad << std::endl << std::endl;

    
	  Canny(edges, edges, 0, 30, 3);


	  int KeyPressed=255;
	  imshow( "Sobel", grad );
	  imshow("edges", edges);
	  

	   KeyPressed=cvWaitKey(10) & 255;
	    if(KeyPressed==27) //KeyPressed==esc
      {
         break;
      }
      if (KeyPressed==112) //KeyPressed==p
      {
		  cv::imwrite("/home/marios/temp/sobelcanny/Moullis1.png",grad);
		  cv::imwrite("/home/marios/temp/sobelcanny/Moullis2.png",edges);
      std::cout << "edges = " << std::endl << " " << grad << std::endl << std::endl;

		  
	  }
	}
  return 0;
  }
