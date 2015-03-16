#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <string>
#include <vector>

void detect_face()
{
    std::string cascade_path="/home/marios/temp/face_detector/haarcascade_frontalface_alt_tree.xml";
    std::string _model_path="/home/marios/temp/face_detector/model.xml";
    
    std::vector<cv::Rect_<int> > faces_total;
      
    //!< Cascade classifier for face detection
    cv::CascadeClassifier	cascade;      
    
    //!<Trained model for face detection
    cv::Ptr<cv::FaceRecognizer> model;
    
    //!< Open default camera
    cv::VideoCapture cap(0); 
    if(!cap.isOpened())  
        exit(0);
    
    cascade.load(cascade_path);
    if(cascade.empty())
    {
      std::cout<<"Could not load cascade classifier";
      exit(0);
    }

    model = cv::createLBPHFaceRecognizer();
    model->load(_model_path);
    cv::Mat img;
    while(1)
    {
        cap >> img;
        
        cv::Mat original(img.size().width,img.size().height,CV_8UC1);
        original = img.clone();
        cv::Mat gray(img.size().width,img.size().height,CV_8UC1);
        cvtColor(original, gray, CV_BGR2GRAY);
        std::vector< cv::Rect_<int> > thrfaces;
        int im_width = 92;
        int im_height = 112;

        if(!cascade.empty())
        {
          //!< Find the faces in the frame:
          cascade.detectMultiScale(gray, thrfaces);
     
          for(int i = 0; i < (thrfaces.size() ? thrfaces.size() : 0); i++)
          {
            //!< Process face by face:
            cv::Rect face_i = thrfaces[i];
            cv::Mat face = gray(face_i);
            cv::Mat face_resized;
            cv::resize(face, face_resized, cv::Size(im_width, im_height), 1.0, 1.0, cv::INTER_CUBIC);
            int prediction = model->predict(face_resized);
            std::cout<<"Prediction"<<prediction<<std::endl;
            rectangle(original, face_i, CV_RGB(0, 255,0), 1);
            //!< Add every element created for each frame, to the total amount of faces
            faces_total.push_back (thrfaces.at(i));
          }
        }
        cv::imshow("face_detector", original);
        if(cv::waitKey(30) >= 0) break;
    }
}

int main()
{
  detect_face();
}
