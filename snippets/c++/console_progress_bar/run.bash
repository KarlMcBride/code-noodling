#/bin/bash

source_dir=src
source_build_dir=build

# Use source directory, then generate make files in build
cmake -H${source_dir} -B${source_build_dir}
# Run build
make -C ${source_build_dir}

./build/progress_bar