#!/bin/bash

if [ $# -eq 0 ]
then
    while [ -z $prefix ]
    do
        echo -n "Enter the prefix, left and right border"
        read prefix bordleft bordright
    done
fi
if [ $# -le 1 -a "$1" != "?" ]
then
    while [ -z $bordleft ]
    do
        echo -n "Enter the left and right border"
        read bordleft bordright
    done
fi
if [ $# -le 2 -a "$1" != "?" ]
then
    while [ -z $bordright ]
    do
        echo -n "Enter the left border"
        read bordright
    done
fi
if [ $# -gt 3 ]
then
    while [ -z $bordright ]
    do
        echo -n "Enter the correct number of arguments"
        read prefix bordleft bordright
    done
fi
if [ "$1" = "?" ]
then
    echo "Specification: $0 <prefix> <leftbord> <rightbord>"
fi

if [ -z $prefix ]
then
    prefix=$1
fi
if [ -z $bordleft ]
then
    bordleft=$2
fi
if [ -z $bordright ]
then
    bordright=$3
fi
if [ "$1" != "?" ]
then
    for fl in ~/lab21/*
    do
        filename=$(basename $fl)
        prefixfile=${filename%.*}
        len=$(stat -c%s "$fl")
        if [[ "$prefixfile" == "$prefix" ]] && [[ "$len" -ge "$bordleft" ]] && [[ "$len" -le "$bordright" ]]
        then
            rm $fl
        fi
    done
fi


