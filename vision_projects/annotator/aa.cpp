#include <iostream>
#include <boost/filesystem.hpp>
using namespace boost::filesystem;
using namespace std;

void fun(const string& dirPath);
int main()
{
    fun("/home");
    return 0;
}

void fun(const string& dirPath)
{
    path p (dirPath); 

    if (exists(p))  
    {
        if (is_regular_file(p))   
            cout << p << " size is " << file_size(p) << '\n';

        else if (is_directory(p))    
            cout << p << "is a directory\n";

        else
            cout << p << "exists, but is neither a regular file nor a directory\n";
    }
    else
        cout << p << "does not exist\n";
}
