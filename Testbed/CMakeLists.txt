cmake_minimum_required(VERSION 3.13.0)
project(TestBed)


set(NLS_TESTBED_SOURCES "src/main.cpp")

add_executable(TestBed ${NLS_TESTBED_SOURCES})
target_link_libraries(TestBed NamelessLib)