cmake_minimum_required(VERSION 3.5)
project(multi_ack)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wformat-security -Wmissing-include-dirs -Wuninitialized -Wtrampolines -Wconversion -Wuseless-cast -Wlogical-op -Wctor-dtor-privacy -Wold-style-cast -Wno-reorder -Wno-unused-parameter -Werror=delete-non-virtual-dtor -Werror=return-type -Werror=implicit -std=c++14 -O2 -lgmpxx -lgmp")

set(SOURCE_FILES
        ack.cpp)

add_executable(multi_ack ${SOURCE_FILES})