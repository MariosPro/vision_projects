/***
 * ******************************************************************
 *
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2015, P.A.N.D.O.R.A. Team.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the P.A.N.D.O.R.A. Team nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 * Authors: Marios Protopapas
 *********************************************************************/
#include "annotator.h"

namespace fs = ::boost::filesystem;
//! Initialization of the static members
std::string Params::folder = "~/Desktop";
//unsigned int Params::width = 0;
//unsigned int Params::height = 0;
int Params::curr_frame = 0;
int Params::num_frames = 0;
std::string Params::prefix = "";
std::string Params::suffix = "jpg";

static int drag = 0;
static cv::Point point;
std::vector<cv::Rect>bbox;
cv::Rect tempBox;
std::vector<int>objectsPerImage;
static int xx = 0;
static int yy = 0;
 std::ofstream annotations_file;
 cv::Mat processedImage;
static void help(char** argv)
{
  std::cout << "\nProvide the absolute path of the directory where the images to be annotated are saved and the image filetype.\n"
         << "Usage: " << argv[0] << " /home/my_folder .jpg\n"
         << std::endl;
}
static void readFromFile(std::string filename)
{
  std::ifstream fileInput;
  fileInput.open("annotations.txt");
  std::string line;
  std::string name;
  int k;
 std::cout << getline(fileInput, line) << " " <<filename << std::endl;
  bbox.resize(objectsPerImage[Params::curr_frame]);
  std::cout << bbox.size() << filename << std::endl;
  while(getline(fileInput, line))
  {
    std::cout << line.substr(1,26) <<std::endl;
    if (line.substr(1,26) == filename)
    {
     std::cout << "Loading annotation for image " << name << " " <<bbox.size() << std::endl;
    for(int i = 0; i < objectsPerImage[Params::curr_frame]; i++)
    {

      fileInput >> name >> k >> bbox[i].x >> bbox[i].y >> bbox[i].width >> bbox[i].height;
    std::cout << " " << bbox[i].x << " " << bbox[i].y << " " << bbox[i].width << " " <<  bbox[i].height;
    }
    }
    else
    {
     std::cout << "Error! Object not found " << filename << std::endl;
    }
  }
  fileInput.close();
  std::cout << std::endl;
}
static void deleteFromFile(std::string filename)
{
  std::ifstream myfile;
  std::ofstream temp;
  std::string line;
  int k=0;
  myfile.open("annotations.txt");
  temp.open("temp.txt");
   while (std::getline(myfile, line))
  {
    std::cout <<"xalooooooo" <<std::endl;
    if (line.substr(1,26)!= filename)
    { k++;
      temp << line << std::endl;
    }
  }
  if(k!=0)

  std::cout << "Object deleted from image "<< filename << std::endl;
  myfile.close();
  temp.close();
  remove("annotations.txt");
  rename("temp.txt", "annotations.txt");
}

static void writeToFile(std::string filename, const std::vector<cv::Rect>& bbox )
{

  annotations_file.open("annotations.txt", std::ios::app | std::ios::out);
  annotations_file << filename <<","; //<< bbox.size() << " ";
  std::cout << "Object annotations for image: " << filename << " " << bbox.size() << " " ;
  std::string in;
  std::cout << "Give category" << std::endl;
  std::cin >> in;
  for(int i = 0; i < bbox.size(); i++)

  {
    annotations_file << in << "," << bbox[i].x << ","<< bbox[i].y << ","  << bbox[i].x+bbox[i].width << "," << bbox[i].y+bbox[i].height; //<< ",";
    std::cout << in << bbox[i].x << ","<< bbox[i].y << ","  << bbox[i].x+bbox[i].width << "," << bbox[i].y+bbox[i].height << ",";
  }

  std::cout  << " saved" << std::endl;
  annotations_file << std::endl;
  annotations_file.close();

}
/**
  @brief Function for capturing mouse events
  @param event [int] Mouse Even
  @param x [int] Bounding box x-coordinate
  @param y [int] Bounding box y-coordinate
  @param flags [int]
  @param param [void*] Pointer to parameter passed in mousecallback function
**/
static void mouseHandler(int event, int x, int y, int flags, void *param )
{

  cv::Mat *img = (cv::Mat *)param;

  xx = x;
  yy = y;
  /* user press left button */
  if (event == CV_EVENT_LBUTTONDOWN && !drag)
  {
    point = cv::Point(x, y);
    drag = 1;
  }

  /* user drag the mouse */
  if (event == CV_EVENT_MOUSEMOVE && drag)
  {
    cv::Mat imgCopy;
    //img->copyTo(imgCopy);
    imgCopy = img->clone();

    cv::rectangle(imgCopy, point, cv::Point(x, y), CV_RGB(255, 0, 0), 3, 8, 0);

    cv::imshow("image", imgCopy);
    cv::waitKey(20);

  }

  /* user release left button */
  if (event == CV_EVENT_LBUTTONUP && drag)
  {
   tempBox = cv::Rect(point.x + 4, point.y + 4, x - point.x - 8, y - point.y - 8);
    drag = 0;
    //objectsPerImage[Params::curr_frame]++;
  }
}

void drawBBox(cv::Mat* image, const cv::Rect& bbox)
{
  cv::rectangle(*image, bbox, CV_RGB(0, 255, 255));

}
void processImage(cv::Mat& image, const std::string& img_name)
{  std::cout << "Processing " << img_name << " image"<<  std::endl;
 cv::Mat current_frame;
 current_frame = image.clone();
 //drawBBox(&current_frame, tempBox);
 if(objectsPerImage[Params::curr_frame]!=0)
   for(int i = 0; i < objectsPerImage[Params::curr_frame]; i++)
  {           drawBBox(&current_frame, bbox[i]);
    }

 cv::imshow("image", current_frame);
 cv::setMouseCallback("image", mouseHandler, &current_frame);
 int keyCode = cv::waitKey(0)&255;
 switch (keyCode)
 {
   case 's': // save annotated object for current frame
   {

          bbox.push_back(tempBox);
          objectsPerImage[Params::curr_frame]++;
         break;

   }
   case 32: //space go to next frame
   {
     if(objectsPerImage[Params::curr_frame] != 0)
       writeToFile(img_name, bbox);
     Params::curr_frame++;
     bbox.clear();
     tempBox.x = tempBox.y = tempBox.width = tempBox.height = 0;
     break;
   }

   case 'd':
   {
     deleteFromFile(img_name);
     objectsPerImage[Params::curr_frame] = 0;
     bbox.clear();
     tempBox.x = tempBox.y = tempBox.width = tempBox.height = 0;
     break;
   }

   case 'p': // go to previous frame
   {
     if(Params::curr_frame != 0)
     Params::curr_frame--;
     if(objectsPerImage[Params::curr_frame] == 0)
        bbox.clear();
     else
        readFromFile(img_name);
     tempBox.x = tempBox.y = tempBox.width = tempBox.height = 0;
     break;
   }
 }

}

void scanFiles( const fs::path & directory, std::string filterFileType, std::vector<std::string>* images )
{
  Params::num_frames=0;
    if( fs::exists( directory ) )
    {
      fs::directory_iterator end ;
        for( fs::directory_iterator iter(directory) ; iter != end ; ++iter )
            if ( (fs::is_regular_file( *iter ) && iter->path().extension().string() == filterFileType))
        {
          //std::cout << iter->path().filename().string() << std::endl ; //this is the one of scanned file names
            Params::num_frames++;


            images->push_back(directory.string()+"/"+iter->path().filename().string());
        }
    }
   std::sort(images->begin(),images->end()) ;

}

bool is_file_exist(const char *fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}


int main( int argc, char** argv )
{
  //help();

if(argc != 3 )
    {
        help(argv);
        return 1;
    }

  //! Argument parsing
  std::string folder = argv[1];
  fs::path p(folder);
  Params::suffix = argv[2];
  if(is_file_exist("annotations.txt"))
     remove("annotations.txt");

  std::vector<std::string> images;
  scanFiles(p, Params::suffix, &images);
   for (int i=0; i<Params::num_frames; i++)
    objectsPerImage.push_back(0);
    std::cout << objectsPerImage.size() << std::endl;

  std::cout << Params::num_frames << " images found in" << folder  << std::endl;

  while(Params::curr_frame < Params::num_frames)
  {
  processedImage = cv::imread(images[Params::curr_frame]);
  processImage(processedImage,images[Params::curr_frame]);

  }


  return 0;
}
