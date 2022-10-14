#!/bin/bash
cd kem
allFolders=$(ls)

for folder in $allFolders
do
    cd $folder
    echo $folder
    ./buildCreateEncapsulations
    echo $folder
    ./runCreateEncapsulations
    echo $folder
    cd ..
done