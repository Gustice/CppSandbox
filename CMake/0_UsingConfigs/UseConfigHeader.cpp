#include <iostream>

#include "Config.h"
const char * myString = ProjectDefined_String;
const int myNumber = ProjectDefined_Number;

int main(int argc, char const *argv[])
{
    
    std::cout << "Hello UseConfigHeader" << std::endl;
    std::cout << "Project-Version is: " << Project_Version_MAJOR << "." << Project_Version_MINOR << std::endl;
    std::cout << "Description: " << myString << " " << myNumber << std::endl;
    return 0;
}

