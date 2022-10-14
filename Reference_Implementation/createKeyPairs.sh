#!/bin/bash
cd kem
allFolders=$(ls)

for folder in $allFolders
do
    cd $folder
    ./buildCreateKeyPairs
    ./runCreateKeyPairs
    cd ..
done