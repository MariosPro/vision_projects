#include<opencv2/opencv.hpp>
#include<iostream>
#include <string>
#include <vector>

#include <boost/algorithm/string/case_conv.hpp>
#include <boost/filesystem.hpp>

static void help();
static void loadFiles(std::vector<std::string>& files, boost::filesystem::path path, const std::
  string& ext);

