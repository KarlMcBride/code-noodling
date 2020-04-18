#include <iostream>

std::string getEnvVar( std::string const & key )
{
    char * val = getenv( key.c_str() );
    return val == NULL ? std::string("") : std::string(val);
}

int main()
{
    const std::string BASH_VAR_NAME = "BASH_VAR";
    std::cout << BASH_VAR_NAME << ": [" << getEnvVar( BASH_VAR_NAME ) << "]" << std::endl;

    return 0;
}