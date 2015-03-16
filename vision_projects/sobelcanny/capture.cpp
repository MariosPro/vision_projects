#include "opencv2/opencv.hpp"
//#include <cv.h>
#include "opencv2/highgui/highgui.hpp"

using namespace cv;


int main(int argc, char** argv){

   VideoCapture cap(0); // open the default camera

   if(!cap.isOpened()) // check if we succeeded
      return -1;

   int scale = 1;
   int delta = 0;
   int ddepth = CV_16S;
   for(;;) {

      Mat edges;
      Mat frame;
      cap >> frame; // get a new frame from camera
      Mat grad ;

      cvtColor(frame, edges, CV_BGR2GRAY);

      //GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
   /// Generate grad_x and grad_y
     //Mat grad_x, grad_y;
     //Mat abs_grad_x, abs_grad_y;

     /// Gradient X
     //Scharr( src_gray, grad_x, ddepth, 1, 0, scale, delta, BORDER_DEFAULT );
     //Sobel(edges, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT );
     //convertScaleAbs( grad_x, abs_grad_x );

     /// Gradient Y
     //Scharr( src_gray, grad_y, ddepth, 0, 1, scale, delta, BORDER_DEFAULT );
     //Sobel(edges, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT );
     //convertScaleAbs( grad_y, abs_grad_y );

     /// Total Gradient (approximate)
     //addWeighted( abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad );
         //Canny(edges, edges, 0, 30, 3);

      imshow("edges", edges);

      if(waitKey(30) >= 0) break;

      // the camera will be deinitialized automatically in VideoCapture destructor
   }
   return 0;

}
