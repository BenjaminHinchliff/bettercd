# CMakeList.txt : CMake project for bcd, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("bcd")

# set C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add source to this project's executable.
add_executable (bcd "bcd.cpp")
