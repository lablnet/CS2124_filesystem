cmake_minimum_required(VERSION 3.16.3)
project(AlphaFileSystem)

set(CMAKE_CXX_STANDARD 20)

add_executable(AlphaFileSystem src/HashTable/HashUtility.h src/vendor/VariadicTable/VariadicTable.h src/HashTable/HashTable.h src/HashTable/HashTable.cpp src/Disk/Disk.h src/utility.h main.cpp)