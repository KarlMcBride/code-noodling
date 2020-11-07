#!/bin/bash

set -e

BUILD_DIR=build

mkdir -p $BUILD_DIR
cd $BUILD_DIR
cmake ..

# Make and run on success
./throw
./define_new_exception
