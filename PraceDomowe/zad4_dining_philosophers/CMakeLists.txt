cmake_minimum_required(VERSION 3.10)
project(dining_philosophers)

set(CMAKE_CXX_STANDARD 17)

set(BINARY ${CMAKE_PROJECT_NAME})

add_executable(${BINARY}_run zad4_dining_philosophers.cpp Fork.cpp Fork.hpp Philosopher.cpp 
                        Philosopher.hpp Table.cpp Table.hpp)
target_link_libraries(${BINARY}_run pthread)
