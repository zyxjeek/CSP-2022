cmake_minimum_required(VERSION 3.24)
project(BigDecimal)

set(CMAKE_CXX_STANDARD 17)

add_executable(BigDecimal main.cpp BigInteger.h)
