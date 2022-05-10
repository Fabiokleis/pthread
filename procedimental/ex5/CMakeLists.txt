cmake_minimum_required(VERSION 3.21)

project(pthread VERSION 0.1)

file(GLOB SOURCE ./src/main.cpp src/**/*.cpp)

add_executable(pthread "${SOURCE}")

target_include_directories(pthread
  PRIVATE
    "${PROJECT_BINARY_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/"
  )
