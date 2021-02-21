#include <iostream>

#include "Config.h"
const char * myString = ProjectDefined_String;
const int myNumber = ProjectDefined_Number;

int main(int argc, char const *argv[])
{
    
    std::cout << "Hello UseConfigHeader" << std::endl;
    std::cout << "Project-Version is: " << Project_Version_MAJOR << "." << Project_Version_MINOR << std::endl;
    std::cout << "Description: " << myString << " " << myNumber << std::endl;

#ifdef USE_FLAG
    std::cout << "NOTE: USE_FLAG was also defined: " << std::endl;
#endif
#ifdef NOT_USE_FLAG
    std::cout << "NOTE: NOT_USE_FLAG was also defined: " << std::endl;
#endif

    return 0;
}

