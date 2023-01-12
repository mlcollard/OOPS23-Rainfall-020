# @file CMakeLists.txt
# 
# CMake files for the rainfall program

cmake_minimum_required(VERSION 3.25)

# project info
project(Rainfall)

# C++17
set(CMAKE_CXX_STANDARD 17)

# Turn on warnings
if (MSVC)
    # warning level 4
    add_compile_options(/W4)
else()
    # standard warnings
    add_compile_options(-Wall)
endif()

# Rainfall program
add_executable(rainfall rainfall.cpp)

# run command
add_custom_target(run $<TARGET_FILE:rainfall> < ${CMAKE_SOURCE_DIR}/demo.csv)

# check command - use diff to check output
find_program(DIFF diff)
find_package(Git QUIET)
if (NOT DIFF STREQUAL "DIFF-NOTFOUND")
    message(STATUS "Check output uses diff: ${DIFF}")
    add_custom_target(check 
        COMMAND $<TARGET_FILE:rainfall> < ${CMAKE_SOURCE_DIR}/demo.csv | ${DIFF} ${CMAKE_SOURCE_DIR}/demo.txt -
    )
elseif(GIT_FOUND)
    message(STATUS "Check output uses git diff: ${GIT}")
    add_custom_target(check 
        COMMAND $<TARGET_FILE:rainfall> < ${CMAKE_SOURCE_DIR}/demo.csv | ${GIT_EXECUTABLE} diff --no-index ${CMAKE_SOURCE_DIR}/demo.txt -
    )
else()
    message(STATUS "Check output is not implemented due to missing diff utilities")
endif()
