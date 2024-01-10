#!/bin/bash

rm -r build

mkdir build

cd build

cmake ..

make

#firefox https://www.youtube.com/watch?v=dQw4w9WgXcQ &

make code-coverage

firefox code-coverage/index.html &
