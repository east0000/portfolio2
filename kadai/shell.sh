#!/bin/sh

#test using
rm result.txt
make clean
make all

./main dic.txt gra.txt text.txt > result.txt

cat result.txt
