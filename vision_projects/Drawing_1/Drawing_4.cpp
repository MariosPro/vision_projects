#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#define w 400

using namespace cv;
void MyLine( Mat img, Point start, Point end );

int main( void ){

  /// Windows names
  
  char rook_window[] = "Drawing 2: Rook";

  /// Create black empty images
  Mat rook_image = Mat::zeros( w, w, CV_8UC1 );
 
  MyLine( rook_image, Point( 200, 200 ), Point(300, 200 ) );
  imshow( rook_window, rook_image );
  imwrite("../../Features/drawing.jpg", rook_image);
   waitKey( 0 );
  return(0);
}
void MyLine( Mat img, Point start, Point end )
{
  for (int i=200; i<203; i++)
      img.at<uchar>(200,i)=255;
}
