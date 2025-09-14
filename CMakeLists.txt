# CMakeList.txt : CMake project for Test, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.16)
project ("Pong")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# TODO: Add tests and install targets if needed.

#set(SDL_TEST OFF)
add_subdirectory(vendor)
add_subdirectory(src)
