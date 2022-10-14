#!/bin/bash
cd kem
allFolders=$(ls)

for folder in $allFolders
do
    cd $folder
    cd nist
    cp ../../ntrulpr653/nist/createKeyPairs.c createKeyPairs.c
    cp ../../ntrulpr653/nist/createEncapsulations.c createEncapsulations.c
    cp ../../ntrulpr653/nist/checkDecapsulations.c checkDecapsulations.c
    cd ..
    cp ../ntrulpr653/buildCreateKeyPairs buildCreateKeyPairs
    cp ../ntrulpr653/buildCreateEncapsulations buildCreateEncapsulations
    cp ../ntrulpr653/buildCheckDecapsulations buildCheckDecapsulations
    cp ../ntrulpr653/runCreateKeyPairs runCreateKeyPairs
    cp ../ntrulpr653/runCreateEncapsulations runCreateEncapsulations
    cp ../ntrulpr653/runCheckDecapsulations runCheckDecapsulations
    cd ..
done