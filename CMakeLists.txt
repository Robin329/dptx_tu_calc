cmake_minimum_required(VERSION 3.10)
project(dptx_tu_calc)

add_executable(dptx_tu_calc video.cpp main.cpp)

set_target_properties(dptx_tu_calc PROPERTIES OUTPUT_NAME "dptx_tu_calc")