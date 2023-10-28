#!/bin/bash

# Convert all Directories (.git is skipped which is good)
for d in */; do
    find $d -type f -exec dos2unix {} \;
done
