cmake_minimum_required(VERSION 3.15)
project(labo5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(labo5
        Customer.cpp
        Customer.h
        main.cpp
        Movie.cpp
        Movie.h
        Rental.h)
