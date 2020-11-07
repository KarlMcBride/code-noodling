#include <libgen.h>

#include <iostream>

#include <stdio.h>
#define EMPTY

#define MACRO_LOG(_strip_path) macro_log(__FILE__, __FUNCTION__, __LINE__, _strip_path)

void macro_log(std::string _file, std::string _function, int _line, bool _strip_path)
{
    if (_strip_path)
    {
        const std::string project_folder = "src";
        size_t position = _file.find(project_folder);
        _file = _file.substr(position);
        std::cout << "macro_log stripped path: " << _file << ":" << _function << ":" << _line << std::endl;
    }
    else
    {
        std::cout << "macro_log full path: " << _file << ":" << _function << ":" << _line << std::endl;
    }
}

void second_function()
{
    MACRO_LOG(true);
    MACRO_LOG(false);
}

int main()
{
    MACRO_LOG(true);
    MACRO_LOG(false);

    second_function();

    return 0;
}