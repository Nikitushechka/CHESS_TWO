cmake_minimum_required(VERSION 3.21)
project(CHESS_TWO)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CHESS_TWO
        Cell.cpp
        Cell.hpp
        Logic_raper.cpp
        Logic_raper.hpp
        main.cpp
        Pieces.cpp
        Pieces.hpp)
