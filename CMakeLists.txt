cmake_minimum_required(VERSION 3.8)

project(udp_test_china)

find_package(Boost 1.83.0 REQUIRED)

include_directories(${Boost_INCLUDE_DIR}, src/includes)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fcoroutines -Wall -Wextra -Werror")

add_executable(udp_test src/main.cpp)