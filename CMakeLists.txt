cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(fetch_test LANGUAGES CXX)

option(BUILD_A "Build A-libraries" OFF)
option(BUILD_B "Build B-libraries" OFF)

add_library(fetch_test SHARED)

target_include_directories(fetch_test PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_sources(fetch_test PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/fetch_test.hpp")
target_sources(fetch_test PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/fetch_test.cpp")

if(BUILD_A)
	add_compile_definitions(-DBUILD_A)
	target_sources(fetch_test PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/a_impl.cpp")
endif()

if(BUILD_B)
	add_compile_definitions(-DBUILD_B)
	target_sources(fetch_test PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/b_impl.cpp")
endif()
