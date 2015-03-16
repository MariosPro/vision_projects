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
 
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <boost/filesystem.hpp>


#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
//#include <cv_bridge/cv_bridge.h>
//#include "ros/ros.h"
//#include <sensor_msgs/Image.h>
//#include <sensor_msgs/image_encodings.h>
//#include <image_transport/image_transport.h>
//#include "std_msgs/String.h"
namespace fs = ::boost::filesystem;
/**
 @struct Params
 @brief Holds essential parameters for image aquisition
**/
struct Params
{
  static std::string folder;  // The folder for the images to be saved
  //static unsigned int width;  // The width for the image to be resized
  //static unsigned int height; // The height of the image to be resized
  static std::string prefix;
  static int curr_frame;
  static int num_frames;
  static std::string suffix;

};

static void help(char** argv);
void processImage(cv::Mat& image, const std::string& img_name);


void scanFiles( const fs::path & directory, std::string filterFileType, std::vector<std::string>* images );
static void writeToFile(std::string filename, const std::vector<cv::Rect>& bbox );
