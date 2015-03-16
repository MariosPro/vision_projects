cmake_minimum_required(VERSION 2.8)
project( SURF_Descriptor )
find_package( OpenCV REQUIRED )
add_executable( SURF_Descriptor SURF_Descriptor.cpp )
target_link_libraries( SURF_Descriptor ${OpenCV_LIBS} )

