#include <iostream>
#include <vector>
#include <string>
#include <boost/filesystem.hpp>

namespace fs = ::boost::filesystem;

// return the filenames of all files that have the specified extension
// in the specified directory and all subdirectories
void get_all(const fs::path& root, const std::string& ext, std::vector<fs::path>& ret)
{
    if(!fs::exists(root) || !fs::is_directory(root)) 
    {
      std::cout << "not a directory" << std::endl;
      return;
    }
    fs::recursive_directory_iterator it(root);
    fs::recursive_directory_iterator endit;

    while(it != endit)
    {
        if(fs::is_regular_file(*it) && it->path().extension() == ext) ret.push_back(it->path().filename());
        ++it;

    }

}

int main( int argc, char** argv)
{
  fs::path p("/home/marios/data/Positive_Images");
  std::cout << p.string() <<std::endl;
  std::string ext=".jpg";
  std::vector<fs::path> ret;
  get_all(p,ext,ret);
  for(int i=0; i<ret.size(); i++)
  std::cout << ret[i].string() <<std::endl;
  return 0;
}
