cmake_minimum_required(VERSION 3.15)

project(LostNFound)

add_executable(LostNFound
  main.cpp
  src/barang.cpp
  src/display.cpp
  src/helper.cpp
  src/setting.cpp
)

target_include_directories(LostNFound PRIVATE include)