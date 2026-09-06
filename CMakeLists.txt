cmake_minimum_required(VERSION 4.4)
project(ASLProject1)

find_package(OpenCV REQUIRED)
set(CMAKE_CXX_STANDARD 20)

add_executable(ASLProject1 main.cpp
        ExportData.cpp
        ExportData.h
        ImageHandler.cpp
        ImageHandler.h)

# Crucial: Tells CMake and CLion where to find the opencv2 folder
target_include_directories(ASLProject1 PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(ASLProject1 PRIVATE ${OpenCV_LIBS})