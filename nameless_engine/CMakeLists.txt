cmake_minimum_required(VERSION 3.13.0)
project(NamelessLib)

option(BUILD_LOGGING "Whether to enable logging capabilities." ON)
option(BUILD_IO "Whether to enable windowing and input support." ON)
option(BUILD_VULKAN "Whether to enable the vulkan renderer." OFF)
option(BUILD_OPENGL "Whether to enable the openGL renderer." ON)
option(BUILD_NLSHARP "Whether to enable CSharp scripting support." OFF)


set(NLSLIB_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/include/")
set(NLSLIB_Vendor_Includes "")
set(NLSLIB_VENDOR_LIBS "")
set(NLSLIB_SOURCES "src/Test.cpp")

if (BUILD_LOGGING)
   string(CONCAT NLSLIB_Vendor_Includes "${CMAKE_SOURCE_DIR}/vendor/loguru")
   string(CONCAT NLSLIB_SOURCES "${CMAKE_SOURCE_DIR}/vendor/loguru/loguru.cpp")
endif()

add_library(NamelessLib STATIC ${NLSLIB_SOURCES})

if (BUILD_LOGGING)
   target_compile_definitions(NamelessLib PUBLIC NLS_BUILD_LOGGING=1)
endif()

target_link_libraries(NamelessLib PUBLIC ${NLSLIB_VENDOR_LIBS})
target_include_directories(NamelessLib PUBLIC ${NLSLIB_INCLUDE_DIRS} ${NLSLIB_Vendor_Includes})