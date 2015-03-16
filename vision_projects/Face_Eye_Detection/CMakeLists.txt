cmake_minimum_required(VERSION 2.8)
project( Face_Eye_Detection )
find_package( OpenCV REQUIRED )
add_executable( Face_Eye_Detection Face_Eye_Detection.cpp )
target_link_libraries( Face_Eye_Detection ${OpenCV_LIBS} )

