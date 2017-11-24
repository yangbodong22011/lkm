# Linux Kernel Module

lkm(Linux Kernel Module)

# env

- Kernel : 3.10.0-514.el7.x86_64
- Make : GNU Make 3.82

# usage

```
$ sh module.sh first         //moudule.sh is a shell script for init
$ cd first
$ vim Makefile
1L:  NAME = first  //notice : 'first' same as directory name
$ make
$ sudo insmod firstmod.ko
$ sudo rmmod firstmod
$ sudo dmesg
...
[113951.098142] Enter Module
[113960.099325] Leave Module
```
