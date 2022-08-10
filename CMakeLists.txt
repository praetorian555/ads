cmake_minimum_required(VERSION 3.24)

project(
	ADS
	VERSION 0.1
	DESCRIPTION "Common Algorithms and Data Structures in C++"
	LANGUAGES CXX)

# Include utils script
include(cmake/utils.cmake)

# Library options
option(ADS_UNITY "Enable unity builds" ON)
option(ADS_SANITIZER "Enable address sanitizer" ON)
option(ADS_TESTS "Build tests" ON)

message(STATUS "ADS_UNITY ${ADS_UNITY}")
message(STATUS "ADS_SANITIZER ${ADS_SANITIZER}")
message(STATUS "ADS_TESTS ${ADS_TESTS}")

# Only do these if this is the main project, and not if it is included through add_subdirectory
if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

	# Let's ensure -std=c++xx instead of -std=g++xx
  	set(CMAKE_CXX_EXTENSIONS OFF)

  	include(cmake/optimized-debug.cmake)

	# Configuration types
	SET(CMAKE_CONFIGURATION_TYPES "Debug;OptimizedDebug;Release" CACHE STRING "Choose configuration: Debug OptimizedDebug Release" FORCE)

 	# Let's nicely support folders in IDEs
  	set_property(GLOBAL PROPERTY USE_FOLDERS ON)

  	# Include cmake scripts here
  	include(cmake/clang-format.cmake)
	include(cmake/cppcheck.cmake)

	# Add project level compiler options
	# ...
endif()

# Adds external dependencies
add_subdirectory(extern)

# The compiled library code is here
add_subdirectory(src)

# Tests
if (${ADS_TESTS})
    add_subdirectory(tests)
endif()

