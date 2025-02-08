cmake_minimum_required(VERSION 3.16)
project(AnagramSolver)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    src/main.cpp
    src/anagram_solver.h 
    src/anagram_solver.cpp
)

add_custom_target(run
    COMMAND AnagramSolver
    DEPENDS AnagramSolver
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

include_directories(include)

add_executable(AnagramSolver ${SOURCES})

# Link necessary libraries
# target_link_libraries(MyProject PRIVATE some_library)
