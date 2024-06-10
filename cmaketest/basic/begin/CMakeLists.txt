project(HelloWorld)
cmake_minimum_required(VERSION 3.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable(hello_world main.cpp)

# cmake -S . -B build
# cmake --build build
# cmake --install build --prefix myInstallationDirectory
