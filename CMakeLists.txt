cmake_minimum_required(VERSION 3.10)
project(Pro)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_DIRECTORY}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_DIRECTORY}")

add_subdirectory(Bacteria)
add_subdirectory(Constellation_Search)
