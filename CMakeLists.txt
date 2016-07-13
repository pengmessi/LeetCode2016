cmake_minimum_required(VERSION 3.5)
project(abc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp LC274.cpp LC287.cpp LC146.cpp LC307.cpp LC304.cpp LC308.cpp LC305.cpp LC304.cpp LC289.cpp LC302.cpp LC297.cpp LC295.cpp LC315.cpp LC260.cpp LC282.cpp LC278.cpp LC273.cpp LC351.cpp LC353.cpp LC360.cpp IncludeHelper.h LC361.cpp LC362.cpp LC363.cpp LC364.cpp)
add_executable(abc ${SOURCE_FILES})