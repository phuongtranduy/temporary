cmake_minimum_required(VERSION 3.0)

#project(mathlib VERSION 1.0.0.3)
project(mathlib VERSION 1.0.0.3 LANGUAGES CXX)
add_library(basic_math)
add_library(mathlib::basic_math ALIAS basic_math)

#add_library(basic_math src/basicmath.hpp) ## okie if add hader file into src
#set_target_properties(basic_math PROPERTIES LINKER_LANGUAGE CXX)
##Avoid following error
# -- Configuring done
# CMake Error: Cannot determine link language for target "basic_math".
# CMake Error: CMake can not determine linker language for target: basic_math
# -- Generating done
# CMake Generate step failed.  Build files cannot be regenerated correctly.

target_sources(basic_math
    PRIVATE
    src/basicmath.cpp
)


configure_file(cmake/mathlib.hpp.in config/mathlib.hpp)

#Since the configured file will be written into the binary tree, we must add that directory to the list of paths to search for include files. Add the following lines to the end of the CMakeLists.txt file:
# phuongtran@phuongtranvbox:~/learningstudying/cmaketest/packaging/mathlib/build<>$tree
# ├── config
# │   └── mathlib.hpp

# target_include_directories(basic_math PUBLIC
#                            "${PROJECT_BINARY_DIR}"
#                            )

target_include_directories(
    basic_math
    PRIVATE src
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_include_directories(
    basic_math
    PRIVATE src
    PUBLIC $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# target_include_directories(basic_math INTERFACE 
#     $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/public>
#     $<INSTALL_INTERFACE:include>            
# )   

# target_link_libraries(basic_math
#     PUBLIC
#     tinyxml2::tinyxml2
# )

set_target_properties(basic_math
  PROPERTIES
    POSITION_INDEPENDENT_CODE ON
)

include(GNUInstallDirs)

message(WARNING "CMAKE_CURRENT_LIST_DIR = ${CMAKE_CURRENT_LIST_DIR}")
message(WARNING "CMAKE_CURRENT_SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR}")
message(WARNING "CMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}")

message(WARNING "CMAKE_BINARY_DIR=${CMAKE_BINARY_DIR}")

message(WARNING "CMAKE_INSTALL_LIBDIR = ${CMAKE_INSTALL_LIBDIR}")
message(WARNING "CMAKE_INSTALL_LIBDIR =${CMAKE_INSTALL_LIBDIR}")
message(WARNING "CMAKE_INSTALL_BINDIR = ${CMAKE_INSTALL_BINDIR}")
message(WARNING "CMAKE_INSTALL_INCLUDEDIR= ${CMAKE_INSTALL_INCLUDEDIR}")
message(WARNING "CMAKE_INSTALL_DATAROOTDIR= ${CMAKE_INSTALL_DATAROOTDIR}")


#install(TARGETS basic_math DESTINATION lib)
install(
    TARGETS basic_math
    EXPORT mathlibTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# install the public headers
#install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})


# install the generated export header
install(
    FILES "${CMAKE_CURRENT_BINARY_DIR}/config/mathlib.hpp"
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/config
)

install(
    FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/basicmath.hpp"
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# configure the CMake package file so the libray can be included with find_package() later
include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    "mathlibConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion ##ExactVersion
  )

configure_package_config_file(
    "${CMAKE_CURRENT_LIST_DIR}/cmake/Config.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/mathlibConfig.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/cmake/mathlib
)


# install(FILES
#   ${CMAKE_CURRENT_BINARY_DIR}/mathlibConfig.cmake
#   ${CMAKE_CURRENT_BINARY_DIR}/mathlibConfigVersion.cmake
#   DESTINATION share/cmake/mathlib
# )

## if disable copying the above config file then error when cmake in testap1
# CMake Error at CMakeLists.txt:11 (find_package):
#   By not providing "Findmathlib.cmake" in CMAKE_MODULE_PATH this project has
#   asked CMake to find a package configuration file provided by "mathlib", but
#   CMake did not find one.

#   Could not find a package configuration file provided by "mathlib" with any
#   of the following names:

#     mathlibConfig.cmake
#     mathlib-config.cmake

#   Add the installation prefix of "mathlib" to CMAKE_PREFIX_PATH or set
#   "mathlib_DIR" to a directory containing one of the above files.  If
#   "mathlib" provides a separate development package or SDK, be sure it has
#   been installed.



# install the CMake targets
install(
    EXPORT mathlibTargets
    FILE mathlibTargets.cmake
    NAMESPACE mathlib::
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/cmake/mathlib
)


# Export targets or packages for outside projects to use them directly from the current project's build tree, without installation.
# See the install(EXPORT) command to export targets from an install tree.
export(EXPORT ${PROJECT_NAME}Targets
  FILE "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Targets.cmake"
  NAMESPACE mathlib::
)

##if we don't export like above then app cannot find  with build folder of this lib like the following error
# phuongtran@phuongtranvbox:~/learningstudying/cmaketest/packaging/testapp1/build<>$cmake ..
# CMake Error at /home/phuongtran/learningstudying/cmaketest/packaging/mathlib/build/mathlibConfig.cmake:27 (include):
#   include could not find requested file:
#     /home/phuongtran/learningstudying/cmaketest/packaging/mathlib/build/mathlibTargets.cmake
# Call Stack (most recent call first):
#   CMakeLists.txt:11 (find_package)




###Actual Output
# CMake Warning at CMakeLists.txt:34 (message):
#   CMAKE_CURRENT_LIST_DIR =
#   /home/phuongtran/learningstudying/cmaketest/packaging/mathlib


# CMake Warning at CMakeLists.txt:35 (message):
#   CMAKE_CURRENT_SOURCE_DIR =
#   /home/phuongtran/learningstudying/cmaketest/packaging/mathlib


# CMake Warning at CMakeLists.txt:36 (message):
  
#   CMAKE_INSTALL_PREFIX=/home/phuongtran/learningstudying/cmaketest/packaging/mathlib/mathlibbin


# CMake Warning at CMakeLists.txt:38 (message):
  
#   CMAKE_BINARY_DIR=/home/phuongtran/learningstudying/cmaketest/packaging/mathlib/build


# CMake Warning at CMakeLists.txt:40 (message):
#   CMAKE_INSTALL_LIBDIR =


# CMake Warning at CMakeLists.txt:41 (message):
#   CMAKE_INSTALL_LIBDIR =


# CMake Warning at CMakeLists.txt:42 (message):
#   CMAKE_INSTALL_BINDIR =


# CMake Warning at CMakeLists.txt:43 (message):
#   CMAKE_INSTALL_INCLUDEDIR=


# CMake Warning at CMakeLists.txt:44 (message):
#   CMAKE_INSTALL_DATAROOTDIR=


#########################################################
#########################################################
#########After having install(GNUInstallDirs)############
#########################################################

# CMake Warning at CMakeLists.txt:42 (message):
#   CMAKE_INSTALL_LIBDIR = lib


# CMake Warning at CMakeLists.txt:43 (message):
#   CMAKE_INSTALL_LIBDIR =lib


# CMake Warning at CMakeLists.txt:44 (message):
#   CMAKE_INSTALL_BINDIR = bin


# CMake Warning at CMakeLists.txt:45 (message):
#   CMAKE_INSTALL_INCLUDEDIR= include


# CMake Warning at CMakeLists.txt:46 (message):
#   CMAKE_INSTALL_DATAROOTDIR= share