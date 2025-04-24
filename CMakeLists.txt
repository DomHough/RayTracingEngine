cmake_minimum_required(VERSION 3.28)
project(RayTracingEngine LANGUAGES CXX)

#set(CMAKE_CXX_STANDARD 23)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

enable_testing()
include(CTest)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.x
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(SFML)
FetchContent_MakeAvailable(googletest)


file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h")
add_library(core ${SOURCES} ${HEADERS})


target_include_directories(core PUBLIC include)
target_compile_features(core PUBLIC cxx_std_17)
target_link_libraries(core PUBLIC sfml-graphics)

add_executable(RayTracingEngine main.cpp)
target_link_libraries(RayTracingEngine PUBLIC core)

add_subdirectory(tests)