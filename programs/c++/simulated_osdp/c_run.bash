#!/bin/bash

BUILD_DIR=build

mkdir -p $BUILD_DIR
cd $BUILD_DIR
cmake ..

# Make and run on success
make && ./executable