#include"annotator.h"


static void help()
{
  std::cout <<"Call: " <<"./annotator  absolute_path image_extension" << std::endl;
  std::cout << "e.g. ./annotator /home/usr/Images .jpg " << std::endl;
}

static void loadFiles(std::vector<std::string>& files, boost::filesystem::path path, const std::string& ext)

{

   
  try 
  { 
    std::cout << boost::filesystem::file_size(path) << std::endl; 
  } 
  catch (boost::filesystem::filesystem_error &e) 
  { 
    std::cerr << e.what() << std::endl; 
  }

  for ( boost::filesystem::directory_iterator it(  path );
        it != boost::filesystem::directory_iterator(); ++it )
  {
    if ( boost::filesystem::is_regular_file( it->status() ) &&
         boost::algorithm::to_lower_copy( it->path().extension()).string()== ext )
    {
      files.push_back( it->path().filename());
    }
  }

  //std::cout << "Number of files: " << files.size() << std::endl;
  //std::copy( files.begin(), files.end(), std::ostream_iterator<std::string>( std::cout, "\n" ) );

}

int main( int argc, char** argv )
{
  help();
  if(argc!=3)
  {
    help();
    exit(0);
  }
  
  //! Argument parsing
  boost::filesystem::path path(argv[1]);
  std::string ext(argv[2]);

  std::vector<std::string> files;
  loadFiles(files, path, ext);

  return 0;
}
