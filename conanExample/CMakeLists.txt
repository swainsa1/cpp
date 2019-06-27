PROJECT(myapp)
cmake_minimum_required(VERSION 3.1)

add_executable(main MainClass.cpp)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)
target_link_libraries(main CONAN_PKG::libcurl)
