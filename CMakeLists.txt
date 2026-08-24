cmake_minimum_required(VERSION 3.21)
project(example)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} main.cpp FindFigures.cpp FindFiguresInvasive.cpp FindFiguresKind.cpp)

#enable_testing()
#add_subdirectory(ut)
