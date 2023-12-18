cmake_minimum_required(VERSION 3.26)
project(RecipeDatabaseSim)

set(CMAKE_CXX_STANDARD 17)

add_executable(RecipeDatabaseSim main.cpp
        CookingOrderProcessor.cpp
        CookingOrderProcessor.h)
