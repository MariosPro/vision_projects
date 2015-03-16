#include "opencv/cv.h"
#include "opencv/cxmisc.h"
#include "opencv/highgui.h"
#include "opencv/cvaux.h"
#include <iostream>
#include <fstream>
using namespace cv;
using namespace std;
int frameHeight=480;
int frameWidth=640;
Point pt1;
Point pt2;
cv::Rect rect;
bool flag=true;
cv::Point point1;
cv::Point point2;

//mouse event handler to indicate pixels(2D) values
void  mouseEvent(int event, int x,int y, int flags, void* param)
{
    Mat* rgb = (Mat*) param;
    int pointxup=0;
	int pointyup=0;
	int pointxdown=0;
	int pointydown=0;
    if (event == CV_EVENT_LBUTTONDOWN)
    {
        point1.x=x;
        point1.y=y;
        rect.x=x;
        rect.y=y;
        printf("Left upper corner\n");
        printf("%d %d\n",x, y);
    }
    if (event == CV_EVENT_RBUTTONDOWN)
    {
        point2.x=x;
        point2.y=y;
        rect.width=x-rect.x;
        rect.height=y-rect.y;
        printf("Right lower corner\n");
        printf("%d %d\n",x, y);
    }

}

int main()
{
	cv::Mat image,src;
  cv::Mat rect_image;
	int KeyPressed=255;
	char temp_name[250];
	
	
	for(int i=1633;i<=3012;i++)
    {
		printf("**********\n");
		printf("[p]: Press p to display selected rectangle\n");
		printf("[esc]: Press esc to proceed to next picture\n");
		/*
		 * Change temp_name according to your directory!!
		 */
		sprintf(temp_name,"/home/marios/holes_data/Negative_Images/negative%d.jpg",i);
		image = cv::imread(temp_name,1);
    src=image.clone();
		if(!image.data)
		{
			cout<<"Cannot open file"<<endl;
		}
		char key = 0;
		while ((int)key != 27)
		{
		namedWindow("test");
		cvSetMouseCallback("test", mouseEvent, &image);
		imshow("test", image);
		KeyPressed=cvWaitKey(10) & 255;
		if(KeyPressed==27) //KeyPressed==esc
			{
				cout<<"image"<<i<<endl;
				break;
			}
       
        if (KeyPressed==112) //KeyPressed==p
			{
			 rectangle(image,rect,cv::Scalar(15,10,158), 9, 8, 0);
			 circle(image, point1,5, cv::Scalar(255,0,0), 3, 8, 0);
			 circle(image, point2,5, cv::Scalar(255,0,0), 3, 8, 0);
			std::cout<<"rectangle's width :"<<rect.width<<endl;
			std::cout<<"rectangle's height :"<<rect.height<<endl;
			 imshow("test", image);
       rect_image = src(rect);

			}
		}
    if(rect_image.rows!=0 && rect_image.cols!=0)
    {
    cv::resize(rect_image, rect_image, cv::Size(640,480));
		sprintf(temp_name,"/home/marios/holes_data/cropped/negative%d.jpg",i);
    imwrite(temp_name, rect_image);
    }
	}
	
	
}
