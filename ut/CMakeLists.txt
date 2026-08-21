cmake_minimum_required(VERSION 3.21)
project(FindFigures_ut LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/ut_bin)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch Catch2 across FetchContent
include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0 # or newest
)
FetchContent_MakeAvailable(Catch2)

# Add testable application
add_executable(findfigures_tests FindFigures_ut.cpp ../FindFigures.cpp)
target_link_libraries(findfigures_tests PRIVATE Catch2::Catch2WithMain)

target_include_directories(findfigures_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)

# Activate CMake system
enable_testing()
include(Catch)
catch_discover_tests(findfigures_tests
  PROPERTIES
        ARGS "-r junit -o ${CMAKE_BINARY_DIR}/test_results.xml"
)

