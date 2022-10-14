#!/bin/bash
cd kem
allFolders=$(ls)

for folder in $allFolders
do
    cd $folder
    echo $folder
    ./buildCheckDecapsulations
    echo $folder
    ./runCheckDecapsulations
    echo $folder
    sleep 3
    cd ..
done