#!/bin/bash

# 
# Running all Projects in order to test them
# 
pwd
scriptPath="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

echo "Testrun" > $scriptPath/runAll.log

for d in */; do
  for sd in $d*/; do
    if [ -f "./${sd}runMe.sh" ]; then
        echo -e "\033[1;33m"
        echo "running ./${sd}runMe.sh :"
        echo -e "\033[0m"

        # Run Script in local directory
        cd $scriptPath/$sd
        "./runMe.sh" >> $scriptPath/runAll.log
        
        # Woring dir back to script directory
        cd $scriptPath
    else
        echo "WARNING: ./${sd} does not contain a 'runMe.sh'"
    fi
  done
done
