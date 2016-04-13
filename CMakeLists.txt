cmake_minimum_required(VERSION 3.5)
project(multi_ack)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -O2 -lboost_system -lboost_thread  -lgmp")

set(SOURCE_FILES
        ack.cpp)

add_executable(multi_ack ${SOURCE_FILES})