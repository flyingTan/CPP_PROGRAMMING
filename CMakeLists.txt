cmake_minimum_required(VERSION 3.0.0)
project(mac_cpp_programming VERSION 0.1.0)

include(CTest)
enable_testing()

# try conditional compilation
SET(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_STANDARD 17)  ## very important !!
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

add_compile_options(-static-libstdc++)
add_compile_options(-fvisibility=hidden)
add_compile_options(-fPIC)


# Add executable 
add_executable(mac_cpp_programming main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
