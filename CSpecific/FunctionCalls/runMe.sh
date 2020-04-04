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

compArgs=""
if [ $# -gt 0 ]; then
case "$1" in
   0) ;; # No action needed
   1) compArgs="-DSTEP=1 " ;;
   *) echo "ERROR: Parameter ${1} is not valid"; exit 1 ;;
esac
echo "Command Call with ${compArgs}"
fi


indent() { sed 's/^/    /'; }
function ProcessFile {
    g++ -c $1.c -o build/$1.o $compArgs
    nm -C build/$1.o  > build/$1.o.nm
    objdump -d build/$1.o  > build/$1.o.odmp

    echo "Relevant Symbols in ${1}.o" >>$2
    nm -C build/$1.o | grep "Eval_" | indent >>$2
    objdump -d build/$1.o | grep "Eval_" | indent >>$2
}

ProcessFile module $outFile
ProcessFile main $outFile

g++ build/main.o build/module.o -o build/main.exe
nm -C build/main.exe > build/main.exe.nm
echo "Relevant Symbols in main.exe" >>$outFile
nm -C build/main.exe | grep "Eval_" | indent >>$outFile


echo "Show build/output.txt"

echo -e "\033[1;30m"
cat $outFile
echo -e "\033[0m"

echo "invoking main file"

echo -e "\033[2;33m" # Light Yellow
./build/main.exe | indent 
echo -e "\033[0m"
