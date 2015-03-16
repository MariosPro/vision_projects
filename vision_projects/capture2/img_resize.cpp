#include <iostream>
#include <fstream>
#include <math.h>
#include <opencv2/opencv.hpp>
 
 cv::Mat img;
 std::stringstream img_name;

int main()
{ 
   for (int i=0; i<10; i++)
  {
    img_name << "/home/marios/pandora_ws/src/pandora_vision/pandora_vision_victim"
    << "/data/"<< "att_dolls/s5/positive" << i+1 << ".jpg";
    img = cv::imread(img_name.str());
    std::cout << "Reading " << img_name.str().c_str() <<img.size() << std::endl;
    cv::Size size(128,96);
    if(img.rows!=128 || img.cols!=96)
    cv::resize(img,img,size);
    cv::imwrite(img_name.str(),img);
    std::cout << "Resizing " << img_name.str().c_str() <<img.size() << std::endl;
    img_name.str(" ");
  }
}
