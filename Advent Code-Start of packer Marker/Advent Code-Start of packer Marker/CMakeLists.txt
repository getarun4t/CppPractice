cmake_minimum_required(VERSION 3.12)
project(YourProjectName)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)

# Download and install Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)

# Add your source files
set(SOURCES
    find_start_of_packet_marker.h
    find_start_of_packet_marker.cpp
    tests.cpp
)

# Add the executable
add_executable(your_executable_name ${SOURCES})

# Include directories for your source files
target_include_directories(your_executable_name PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Link against Google Test
target_link_libraries(your_executable_name gtest gtest_main)

# Enable testing
enable_testing()

# Add the test executable
add_test(NAME your_test_name COMMAND your_executable_name)
