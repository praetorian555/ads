# Collect all header files so that we can add them to the IDE later
file(GLOB_RECURSE PRIVATE_SOURCE_LIST CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/tests/*[.h|.c|.cpp]")
file(GLOB_RECURSE UNITY_SOURCE_LIST CONFIGURE_DEPENDS "${PROJECT_BINARY_DIR}/tests/*.cxx")

# Make an automatic library - will be static or dynamic based on user setting
add_executable(ads_tests ${PRIVATE_SOURCE_LIST})

# add math library dependency
target_link_libraries(ads_tests ads gtest)

# All users of this library will need C++ 20
target_compile_features(ads_tests PUBLIC cxx_std_20)

# Compiler options
target_compile_options(ads_tests PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/MP>)

# Enable unity build
if (ADS_UNITY)
    set_target_properties(ads_tests PROPERTIES UNITY_BUILD TRUE)
endif()

source_group(
  TREE "${PROJECT_SOURCE_DIR}/tests"
  PREFIX "Tests"
  FILES ${PRIVATE_SOURCE_LIST}
)

if (ADS_UNITY)
  source_group(
    TREE "${PROJECT_BINARY_DIR}/tests/CMakeFiles/ads_tests.dir/Unity"
    PREFIX "Unity"
    FILES ${UNITY_SOURCE_LIST}
  )
endif()