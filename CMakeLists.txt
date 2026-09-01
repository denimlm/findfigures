cmake_minimum_required(VERSION 3.21)
project(example)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CXX_ERRORS -Wall -Wextra -Wpedantic -Wshadow -Wconversion)


add_executable(${PROJECT_NAME} main.cpp FindFigures.cpp FindFiguresInvasive.cpp FindFiguresKind.cpp)

target_compile_options(${PROJECT_NAME} PRIVATE ${CXX_ERRORS})
#enable_testing()
#add_subdirectory(ut)
