#!/bin/bash
cd kem
allFolders=$(ls)

for folder in $allFolders
do
    cd $folder
    ./buildEncap
    ./runEncap
    ./buildDecap
    ./runEncap
    ./buildRand
    ./runRand
    cd ..
done