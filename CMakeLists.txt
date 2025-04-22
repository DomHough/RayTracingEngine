cmake_minimum_required(VERSION 3.28)
project(RayTracingEngine LANGUAGES CXX)

#set(CMAKE_CXX_STANDARD 23)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.x
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)


file(GLOB_RECURSE SOURCES "src/*.cpp" "include/*.h")
add_executable(RayTracingEngine main.cpp ${SOURCES})

target_include_directories(RayTracingEngine PRIVATE ${SFML_SOURCE_DIR}/include)
target_compile_features(RayTracingEngine PRIVATE cxx_std_17)
target_link_libraries(RayTracingEngine PRIVATE sfml-graphics)