#!/bin/bash
## We create a repository to compile the project in
# We empty it to avoid any problem
rm -r build
mkdir build
cd build

# We use CMake for the compilation
cmake ..
make

#firefox https://www.youtube.com/watch?v=dQw4w9WgXcQ &

#This runs the test
make code-coverage

#This open the code coverage summary
#firefox code-coverage/index.html &
