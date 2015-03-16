cmake_minimum_required(VERSION 2.8)
project( FeatureDetection )
find_package( OpenCV REQUIRED )
add_executable( FeatureDetection FeatureDetection.cpp )
target_link_libraries( FeatureDetection ${OpenCV_LIBS} )

