# Collect all header files so that we can add them to the IDE later
file(GLOB_RECURSE PUBLIC_SOURCE_LIST CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/*.h")
file(GLOB_RECURSE PRIVATE_SOURCE_LIST CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/src/*[.h|.c|.cpp]")
file(GLOB_RECURSE UNITY_SOURCE_LIST CONFIGURE_DEPENDS "${PROJECT_BINARY_DIR}/src/*.cxx")

# Make an automatic library - will be static or dynamic based on user setting
add_library(ads ${PRIVATE_SOURCE_LIST} ${PUBLIC_SOURCE_LIST})

# We need this directory, and users of our library will need it too
target_include_directories(ads PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Private include path
target_include_directories(ads PRIVATE ${PROJECT_SOURCE_DIR}/src)

# Enable unity build
if (ADS_UNITY)
    set_target_properties(ads PROPERTIES UNITY_BUILD TRUE)
endif()

# All users of this library will need at C++20
target_compile_features(ads PUBLIC cxx_std_20)

# Compiler options
target_compile_options(ads PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/MP>)
if (ADS_SANITIZER)
  target_compile_options(ads PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/fsanitize=address>)
endif()

# IDEs should put the headers in a nice place
source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "API"
  FILES ${PUBLIC_SOURCE_LIST})
source_group(
  TREE "${PROJECT_SOURCE_DIR}/src"
  PREFIX "Implementation"
  FILES ${PRIVATE_SOURCE_LIST})
if (RNDR_UNITY)
  source_group(
    TREE "${PROJECT_BINARY_DIR}/src/CMakeFiles/ads.dir/Unity"
    PREFIX "Unity"
    FILES ${UNITY_SOURCE_LIST})
endif()
