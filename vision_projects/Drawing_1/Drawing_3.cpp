#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#define w 400

using namespace cv;
void MyLine( Mat img, Point start, Point end );

int main( void ){

  /// Windows names
  
  char rook_window[] = "Drawing 2: Rook";

  /// Create black empty images
  Mat rook_image = Mat::zeros( w, w, CV_8UC3 );
  //rectangle( rook_image,Point( 0, 0 ),Point( w, w),Scalar( 255, 255, 255 ),-1,8 );
  MyLine( rook_image, Point( 200, 200 ), Point(203, 200 ) );
  imshow( rook_window, rook_image );
  imwrite("../../Features/drawing.jpg", rook_image);
   waitKey( 0 );
  return(0);
}
void MyLine( Mat img, Point start, Point end )
{
  int thickness = 1;
  int lineType = 8;
  line( img,
    start,
    end,
    Scalar( 255, 255, 255 ),
    thickness,
    lineType );
}
