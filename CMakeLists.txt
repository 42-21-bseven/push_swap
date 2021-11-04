cmake_minimum_required(VERSION 3.20)
project(push_swap C)

set(CMAKE_C_STANDARD 11)

#include_directories(.)

#add_executable(push_swap
#        push_swap.c)

#add_executable(./src/*.c ./include s/philo_one.h)
file(GLOB SOURCE_FILES *.c *.h)
add_executable(push_swap ${SOURCE_FILES})