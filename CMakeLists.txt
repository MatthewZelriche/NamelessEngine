cmake_minimum_required(VERSION 3.16)
project(NamelessEngine)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build/${CMAKE_BUILD_TYPE}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build/${CMAKE_BUILD_TYPE}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build/${CMAKE_BUILD_TYPE}/bin")

# Options
option(BUILD_TESTBED "ON if you want to build the testbed" ON)

# Compile settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(MSVC)
   add_compile_options(/W4)
else()
   add_compile_options(-Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Wunused)
endif()

add_subdirectory("${PROJECT_SOURCE_DIR}/nameless_engine")
if (${BUILD_TESTBED})
   add_subdirectory("${PROJECT_SOURCE_DIR}/testbed")
endif()