cmake_minimum_required(VERSION 3.0)

project(mathlib VERSION 1.0.0.3 LANGUAGES CXX)
add_library(basic_math)
target_sources(basic_math
    PRIVATE
    src/basicmath.cpp
)
configure_file(cmake/mathlib.hpp.in config/mathlib.hpp)

#Since the configured file will be written into the binary tree, we must add that directory to the list of paths to search for include files. Add the following lines to the end of the CMakeLists.txt file:
# phuongtran@phuongtranvbox:~/learningstudying/cmaketest/packaging/mathlib/build<>$tree
# ├── config
# │   └── mathlib.hpp
target_include_directories(basic_math PUBLIC
                           "${PROJECT_BINARY_DIR}"
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

message(WARNING "CMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}")

message(WARNING "CMAKE_BINARY_DIR=${CMAKE_BINARY_DIR}")

install(TARGETS basic_math DESTINATION lib)