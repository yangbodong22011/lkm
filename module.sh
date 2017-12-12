#!/bin/bash

pwd=$(cd `dirname $0`; pwd)
dirname=$1
filename=`echo $dirname | awk -F "/" '{print $NF}'`
mkdir $pwd/$dirname
cp $pwd/Makefile $pwd/$dirname
cp $pwd/module.c $pwd/$dirname/$filename.c
