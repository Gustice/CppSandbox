/**
 * @brief C-Make-Evaluation
 * @details This is a example CMake-Project based on a tutorial provided by cmake.org
 *      Tutorial can be found under: https://cmake.org/cmake/help/latest/guide/tutorial/index.html
 *      Demo Sourc is located at: https://github.com/Kitware/CMake/tree/master/Help/guide/tutorial
 * @param argc 
 * @param argv 
 * @return int 
 * 
 * @todo Next Step 5
 */


#include <stdio.h>
#include <string>
#include <iostream>

#include "Version.h"
#include "Config.h"
#include "process.h"
#include "dynLib.h"

#ifdef USE_STATLIB
  #include "statLib.h"
  void PrintUsageOfStaticLib(void)
  {
    printf("## Static Library is used \n");
    CallHelper();
  }
#else
  void PrintUsageOfStaticLib(void) {
    printf("## Static Library is not used \n");
  }
#endif


int main(int argc, char const *argv[])
{
    printf("########################\n");
    printf("Entering main ... \n");
    printf("Version: %d%c%d \n", DEMO_APP_VERSION_MAJOR,'.', DEMO_APP_VERSION_MINOR);
    printf("########################\n");

    if (InitCore() == OpStatus::Initialized) {
        (void)StartCore();
    }

    printf("Returned from call %d \n ", Prc_ProcessCall(1));
    PrintUsageOfStaticLib();
    

    if (argc < 2) {
        std::cout << "Error: Too little arguments"; 
        return 1;
    }

    const double inputValue = std::stod(argv[1]);
    double outputValue = inputValue;
    std::cout << "The result of " << inputValue << " is " << outputValue
            << std::endl;

    return 0;
}
