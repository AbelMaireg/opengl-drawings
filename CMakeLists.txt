cmake_minimum_required(VERSION 3.10)
project(OpenGLProject)


set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(OpenGL REQUIRED)

find_package(GLUT REQUIRED)

add_executable(bin src/main.cpp)

# Link OpenGL and GLUT libraries
target_link_libraries(bin OpenGL::GL GLUT::GLUT)
