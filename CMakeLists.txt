cmake_minimum_required(VERSION 3.13)
project(hmltotex)
add_library(hmltotex SHARED Lib.cc hwpEqToTex.cpp)