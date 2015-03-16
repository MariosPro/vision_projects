#include "opencv2/opencv.hpp"
	
	
	int main()
	{
		cv::VideoCapture cap(0); // open the default camera

		if(!cap.isOpened()) // check if we succeeded
		{
			return -1;
		}

		cv::Mat edges;
		
		for(;;)

		{
			cv::Mat frame;

			cap >> frame; // get a new frame from camera


			imshow("frame", frame);
				
		   int KeyPressed=255;   			
		   KeyPressed=cvWaitKey(10) & 255;
			if(KeyPressed==27) //KeyPressed==esc
		  {
			 break;
		  }
		  int i=0;
		  for(;;)
		  {
			  if (KeyPressed==112) //KeyPressed==p
			  {
				  cv::imwrite("image.png",frame);
				  
			  }
		  }

		  if(cv::waitKey(30) >= 0) break;
		}

			// the camera will be deinitialized automatically in VideoCapture destructor

			return 0;

	}
