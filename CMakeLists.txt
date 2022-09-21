cmake_minimum_required(VERSION 3.23)
project(TaDS_LAB1)

set(CMAKE_CXX_STANDARD 23)

add_executable(TaDS_LAB1 main.cpp Menu/MyMenu.cpp Menu/MyMenuItem.cpp Menu/MyMenu.h Menu/MyMenuItem.h Models/BidList.cpp Models/BidList.h StartProgram.h)
