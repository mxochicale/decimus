cmake_minimum_required(VERSION 1.8)

set(PRJ_NAME kproject)
project(${PRJ_NAME})

include_directories(~/.lib_dependencies/armadillo-5.100.1/include)
include_directories(~/.lib_dependencies/boost-1.58.0/include)

include_directories(/usr/include/libxml2/)
set(LIBS lapack blas ~/.lib_dependencies/boost-1.58.0/lib64/libboost_system.so boost_system)
#set(LIBS /usr/lib/libarmadillo.so lapack blas /usr/local/lib/libmlpack.so mlpack)

# set _REENTRANT flag
ADD_DEFINITIONS(-D_REENTRANT)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
 
add_executable(${PRJ_NAME} Decimus.cpp RazorAHRS.cpp main.cpp)
target_link_libraries(${PRJ_NAME} ${LIBS})
