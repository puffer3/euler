cmake_minimum_required(VERSION 3.10)

# set the project name
project(Eulers)

# add the executable
add_executable(Eulers euler13.cpp)

# Include array .txt file
configure_file(euler13numbers.txt ${CMAKE_BINARY_DIR}/euler13numbers.txt COPYONLY)
