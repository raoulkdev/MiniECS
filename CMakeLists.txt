cmake_minimum_required(VERSION 3.30)
project(MiniECS)

set(CMAKE_CXX_STANDARD 20)

add_executable(MiniECS src/main.cpp
        src/modules/module_base/Module.cpp
        src/modules/module_base/Module.h
        src/unit/Unit.cpp
        src/unit/Unit.h)
