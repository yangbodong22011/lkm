cmd_/home/yangbodong/kernel/hello/hellomod.o := ld -Map /var/tmp/hello.txt   -r -o /home/yangbodong/kernel/hello/hellomod.o /home/yangbodong/kernel/hello/hello.o ; scripts/mod/modpost /home/yangbodong/kernel/hello/hellomod.o