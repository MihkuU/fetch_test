cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(fetch_test LANGUAGES CXX)

option(BUILD_A "Build A-libraries" OFF)
option(BUILD_B "Build B-libraries" OFF)

add_library(${PROJECT_NAME} SHARED)

target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_sources(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/fetch_test.hpp")
target_sources(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/fetch_test.cpp")

### BUILD
if(BUILD_A)
	target_compile_definitions(${PROJECT_NAME} PUBLIC -DBUILD_A)
	target_sources(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/a_impl.cpp")
endif()

if(BUILD_B)
	target_compile_definitions(${PROJECT_NAME} PUBLIC -DBUILD_B)
	target_sources(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/b_impl.cpp")
endif()

get_target_property(assballs fetch_test COMPILE_DEFINITIONS)
message("shitballs: ${assballs}")

### INSTALLATION
#include(GNUINstallDirs)
#install(TARGETS fetch_test
#	EXPORT fetch_testTargets
#	PUBLIC_HEADER DESTINATION ${}
#)
