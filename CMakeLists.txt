# Set the minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Name the project and specify the programming language
project(MyCProject C)

# Set the C standard (optional)
set(CMAKE_C_STANDARD 17)

# Define the source directories
set(BST ${CMAKE_SOURCE_DIR}/BinarySearchTree)
#set(SRC2_DIR ${CMAKE_SOURCE_DIR}/src2)

# Add an executable with the source files
add_executable(tests_bst ${BST}/tests_bst.c ${BST}/traverse_bst.c ${BST}/insert_bst.c
        ${BST}/search_bst.c ${BST}/delete_bst.c)
# Specify the output directory for the executable
set_target_properties(tests_bst PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/builds)