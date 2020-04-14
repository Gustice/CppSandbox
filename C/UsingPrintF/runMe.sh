#!/bin/bash

# 
# Compilation of sandbox-programm and generating of dumps for further analisis.
# 

# Help prompt #
if [[ ( "$1" == "-h" ) || ( "$1" == "--help" ) ]]; then
    echo "Usage: `BashName $0` [-h]"
    echo "  Build the project with different configurations"
    echo
    echo "  -h, --help           Show this help text"
    exit 0
fi

# Generic information for report
outFile=build/output.txt
exTime=$( date +%Y-%m-%d_%H:%M:%S )
scriptPath="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

# Make build directory if not present
if [ ! -d $scriptPath/build ]; then
    mkdir build
fi

# Print generic information into report
echo "Execution of build-script with parameter "$1 >$outFile
echo "Execution time: "$exTime >>$outFile
echo "Script started from $(pwd)" >>$outFile
echo "" >> $outFile

# Function for indentation
indent() { sed 's/^/    /'; }

# Compile singe c file and invoke executable
g++ main.c -o build/main.exe
echo "invoking main executable"

echo -e "\033[2;33m" # Light Yellow
./build/main.exe | indent 
echo -e "\033[0m"
