#!/bin/bash

pwd=$(cd `dirname $0`; pwd)
dirname=$1
mkdir $pwd/$dirname
cp $pwd/Makefile $pwd/$dirname
cp $pwd/module.c $pwd/$dirname/$dirname.c
