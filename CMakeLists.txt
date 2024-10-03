# Set the minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Name the project and specify the programming language
project(MyCProject C)

# Set the C standard (optional)
set(CMAKE_C_STANDARD 17)

# Define the source directories
set(BST ${CMAKE_SOURCE_DIR}/BinarySearchTree)
# Add an executable with the source files
add_executable(BinarySearchTreeTests ${BST}/BinarySearchTreeTests.c ${BST}/BinarySearchTree.c)

#set(SRC2_DIR ${CMAKE_SOURCE_DIR}/src2)