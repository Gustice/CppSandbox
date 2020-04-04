#!/bin/bash

##########
## HELP ##
##########
if [[ ( "$1" == "-h" ) || ( "$1" == "--help" ) ]]; then
    echo "Usage: `BashName $0` [-h]"
    echo "  Build the project with different configurations"
    echo
    echo "  -h, --help           Show this help text"
    echo "  " #@todo Show instructions
    exit 0
fi

outFile=build/output.txt
exTime=$( date +%Y-%m-%d_%H:%M:%S )
scriptPath="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

if [ ! -d $scriptPath/build ]; then
    mkdir build
fi

echo "Execution of build-script with parameter "$1 >$outFile
echo "Execution time: "$exTime >>$outFile
echo "Script started from $(pwd)" >>$outFile
echo "" >> $outFile

function ProcessFile {
    g++ -c $1.cpp -o build/$1.o
    nm -C build/$1.o  > build/$1.o.nm
  
    echo "Relevant Symbols in ${1}.o" >>$2
    nm -C build/$1.o | grep "Eval_"  >>$2
}

ProcessFile module $outFile
ProcessFile main $outFile

g++ build/main.o build/module.o -o build/main.exe
nm -C build/main.exe > build/main.exe.nm
echo "Relevant Symbols in main.exe" >>$outFile
nm -C build/main.exe | grep "Eval_"  >>$outFile


echo "Show build/output.txt"
echo -e "\033[1;30m"
cat $outFile
echo "Test"

echo -e "\033[2;33m" # Light Yellow
echo "invoking main file"
./build/main.exe

echo -e "\033[0m"
