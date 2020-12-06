cmake_minimum_required(VERSION 3.17)
project(pongcpp)

set(CMAKE_CXX_STANDARD 14)
set(SFML_DIR SFML-2.5.1/lib/cmake/SFML)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(pongcpp main.cpp Game.h Game.cpp stdafx.cpp stdafx.h SplashScreen.cpp SplashScreen.h)
target_link_libraries(pongcpp sfml-graphics sfml-audio)