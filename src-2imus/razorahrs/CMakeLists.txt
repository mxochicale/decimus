cmake_minimum_required(VERSION 1.8)

set(PRJ_NAME kproject)
project(${PRJ_NAME})



include_directories(~/.lib_dependencies/eigen-3.2.8/include/eigen3)
## include_directories(~/.lib_dependencies/armadillo-5.100.1/include)
## include_directories(/usr/include/libxml2/)


# set _REENTRANT flag
ADD_DEFINITIONS(-D_REENTRANT)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(${PRJ_NAME} RazorAHRS.cpp main.cpp)
target_link_libraries(${PRJ_NAME} ${LIBS})
