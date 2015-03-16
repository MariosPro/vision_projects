	#include "opencv2/opencv.hpp"
	
	
	int main()
	{
		cv::VideoCapture cap(1); // open the default camera

		if(!cap.isOpened()) // check if we succeeded
		{
			return -1;
		}

		//cv::Mat edges;

		//namedWindow("edges",1);

		for(;;)

		{
			cv::Mat frame;

			cap >> frame; // get a new frame from camera

			//cvtColor(frame, edges, CV_BGR2GRAY);

			//GaussianBlur(edges, edges, cv::Size(7,7), 1.5, 1.5);

			//Canny(edges, edges, 0, 30, 3);

			imshow("edges", frame);

			if(cv::waitKey(30) >= 0) break;
		}

			// the camera will be deinitialized automatically in VideoCapture destructor

			return 0;

	}
