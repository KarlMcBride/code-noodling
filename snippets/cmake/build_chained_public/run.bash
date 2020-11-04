#!/bin/bash

BUILD_DIR=build

mkdir -p build
cd build
cmake ..
make
# Run
./src/build_chained_public