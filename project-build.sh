#!/bin/bash

cd ./prj-build

rm -f *.asm
rm -f *.ihx
rm -f *.lk
rm -f *.lst
rm -f *.map
rm -f *.mem
rm -f *.rel
rm -f *.rst
rm -f *.sym

rm -rf CMakeFiles/   
rm -f CMakeCache.txt
rm -f Makefile
rm -f cmake_install.cmake

cmake -DCMAKE_SYSTEM_NAME=Generic -DCMAKE_C_COMPILER=sdcc .
make all

cd -

