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
    echo " [0]: Mainfile only"
    echo "  1 : Embed Module"
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

# Set compiler arguments according to called mode
compArgs=""
if [ $# -gt 0 ]; then
case "$1" in
   0) ;; # No action needed
   1) compArgs="-DSTEP=1 " ;;
   *) echo "ERROR: Parameter ${1} is not valid"; exit 1 ;;
esac
echo "Command Call with ${compArgs}"
fi

# Function for indentation
indent() { sed 's/^/    /'; }

# Function for single file analisis
function ProcessFile {
    g++ -c $1.c -o build/$1.o $compArgs         # Compile only
    nm -C build/$1.o  > build/$1.o.nm           # print 
    objdump -C -d build/$1.o  > build/$1.o.ddmp # Print assembly
    objdump -C -x build/$1.o  > build/$1.o.xdmp # Print all header
    readelf -a build/$1.o  > build/$1.o.aelf    # Print elf file

    # Print some related info int report
    echo "Relevant Symbols in ${1}.o" >>$2
    nm -C build/$1.o | grep "Eval_" | indent >>$2
}

ProcessFile module $outFile
ProcessFile main $outFile

# Like ProcessFile but applied for linked main
g++ build/main.o build/module.o -o build/main.exe
nm -C build/main.exe > build/main.exe.nm
echo "Relevant Symbols in main.exe" >>$outFile
nm -C build/main.exe | grep "Eval_" | indent >>$outFile

objdump -C -d build/main.exe  > build/main.exe.o.ddmp
objdump -C -x build/main.exe  > build/main.exe.o.xdmp
readelf -a build/main.exe  > build/main.exe.o.aelf

# Show report to propmt
echo "Show build/output.txt"

echo -e "\033[1;30m"
cat $outFile
echo -e "\033[0m"

# Show compiled programm propmt
echo "invoking main executable"

echo -e "\033[2;33m" # Light Yellow
./build/main.exe | indent 
echo -e "\033[0m"
