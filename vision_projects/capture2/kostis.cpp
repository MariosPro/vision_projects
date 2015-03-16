#include "opencv2/opencv.hpp"
#include <stdio.h>
#include <iostream>
	
	
	int main()
	{
    for(;;)
    {
    std::cout <<"bitch!"<<std::endl;
    }
    char ch[30];
    int i=1;
		cv::VideoCapture cap(0); // open the default camera

		if(!cap.isOpened()) // check if we succeeded
		{
			return -1;
		}
		   
       cv::Mat frame;
       int KeyPressed=255;   			
		   KeyPressed=cvWaitKey(100) & 255;

        
      if(KeyPressed==115) //!< KeyPressed==s
      {
        while(1)
        {
        KeyPressed=cvWaitKey(10) & 255;
        if(KeyPressed==27) //KeyPressed==esc
        {
         break;
        }
       cap.grab();
       cap.retrieve(frame);
       cv::imshow("Current",frame);
       cv::waitKey(10);

       char temp_name[50];
       sprintf(temp_name,"negatives/negative%d.jpg",i+1);
       //sprintf(temp_name,"positive1/positive%d.jpg",i+1);
       //sprintf(temp_name,"positive2/positive%d.jpg",i+1);
       cv::imwrite(temp_name,frame);
       std::cout<<"Image "<<temp_name<<" saved"<<std::endl;
       i++;
       usleep(500000);
        }
       
      }
            

			// the camera will be deinitialized automatically in VideoCapture destructor

      cvDestroyAllWindows();  
      cv::VideoCapture release; 
			return 0;

	}
