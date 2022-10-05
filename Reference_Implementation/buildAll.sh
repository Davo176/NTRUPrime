#!/bin/bash
cd kem
allFolders=$(ls)

for folder in $allFolders
do
    cd $folder
    make kat_encap
    make kat_kem_encap.rsp
    make kat_decap
    make kat_kem_decap.rsp
    make kat_rand
    make kat_kem_rand.rsp
    cd ..
done