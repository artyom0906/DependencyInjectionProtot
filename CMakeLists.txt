cmake_minimum_required(VERSION 3.22)
project(CLI)

set(CMAKE_CXX_STANDARD 20)

add_executable(CLI main.cpp src/model/A.h src/controller/AController.h src/model/a/AA.h src/model/a/AB.h src/model/a/AC.h src/infrastructure/service/IService.h)
