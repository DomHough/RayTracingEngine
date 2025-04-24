# Collect all test files
file(GLOB TEST_SOURCES *.cpp)

# Create test executable
add_executable(UnitTests ${TEST_SOURCES})

# Link with GoogleTest and your target
target_link_libraries(UnitTests gtest_main core)
target_include_directories(core PUBLIC include)

# Register test with CTest
include(GoogleTest)
gtest_discover_tests(UnitTests)