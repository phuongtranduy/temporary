cmake_minimum_required(VERSION 3.0)
project(testapp1)
#set(mathlib_DIR "../mathlib/mathlibbin/share/cmake/mathlib/mathlibbin/share/cmake/mathlib") ##cannot work with relativepath
#set(mathlib_DIR "../mathlib/mathlibbin/share/cmake/mathlib/mathlibbin/share/cmake/mathlib") ##cannot work with relativepath
#set(mathlib_DIR "/home/phuongtran/learningstudying/cmaketest/packaging/mathlib/mathlibbin/share/cmake/mathlib")
set(mathlib_DIR "/home/phuongtran/learningstudying/cmaketest/packaging/mathlib/build") ##check with build folder
# f(NOT mathlib_FOUND)
# 	find_package(mathlib REQUIRED)
# endif()

find_package(mathlib REQUIRED)
add_executable(testapp1 main.cpp)
target_link_libraries(testapp1 PRIVATE mathlib::basic_math)
# target_include_directories(testapp1 PRIVATE ../mathlib/src)
# target_link_directories(testapp1 PRIVATE ../mathlib/build)
# target_link_libraries(testapp1 PRIVATE basic_math)