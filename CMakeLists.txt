cmake_minimum_required(VERSION 3.16)
project(jhelper)

add_executable(output output/main.cpp)
add_executable(testrunner testrunner/main.cpp)
add_executable(generator generator/generator.cpp)
file(GLOB TASKS "tasks/*.cpp")
file(GLOB_RECURSE HEADERS "atcoder_library/*.hpp")

ADD_DEFINITIONS(-std=c++17)

add_executable(test ${TASKS} ${HEADERS})
add_executable(main main.cpp)
