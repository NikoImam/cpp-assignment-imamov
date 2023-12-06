cmake_minimum_required(VERSION 3.16)
project(hw11 LANGUAGES CXX)
find_package(Boost REQUIRED COMPONENTS filesystem program_options)

add_executable(hw11 hw11.cpp)
target_link_libraries(hw11 Boost::program_options)
target_link_libraries(hw11 Boost::filesystem)