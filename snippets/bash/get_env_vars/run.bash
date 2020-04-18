#!/bin/bash

export BASH_VAR="Text from bash"

mkdir -p build
cd build

cmake ..
make
./executable