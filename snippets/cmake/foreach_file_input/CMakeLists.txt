cmake_minimum_required(VERSION 3.7.2)

file(STRINGS source_file.txt source_list)
foreach(line ${source_list})
    message("line: ${line}")
endforeach()
