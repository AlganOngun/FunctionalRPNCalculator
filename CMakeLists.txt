cmake_minimum_required (VERSION 3.8)

project(RPN CXX)
set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(RPN main.cpp)
target_link_libraries(RPN ${CONAN_LIBS})
