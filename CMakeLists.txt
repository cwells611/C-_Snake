cmake_minimum_required(VERSION 3.12)
project(Snake)

set(CMAKE_CXX_STANDARD 14)

include_directories("C:/mingw/include")
include_directories("C:/mingw64/include")
include_directories("C:/mingw64/mingw64/include")
include_directories("C:/mingw64/x86_64-w64-mingw32/include")

add_executable(Snake main.cpp Snake.cpp Snake.h Food.cpp Food.h)

target_link_directories(Snake PUBLIC "C:/mingw/lib")
target_link_directories(Snake PUBLIC "C:/mingw64/lib")
target_link_directories(Snake PUBLIC "C:/mingw64/mingw64/lib")
target_link_directories(Snake PUBLIC "C:/mingw64/x86_64-w64-mingw32/lib")

target_link_libraries(Snake sfml-graphics sfml-system sfml-window sfml-main)
