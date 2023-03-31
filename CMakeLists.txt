cmake_minimum_required(VERSION 3.0)

project(Week8 CXX)

include_directories("C:\\Program Files\\Java\\jdk-15.0.2\\include")
include_directories("C:/Program Files/Java/jdk-15.0.2/include/win32")

find_package(OpenMP REQUIRED)
if(OPENMP_FOUND)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

add_library(week8 SHARED week8.h week8.cpp)

set_target_properties(week8 PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set_target_properties(week8 PROPERTIES OUTPUT_NAME "Week8")

set_target_properties(week8 PROPERTIES CXX_STANDARD 11)
