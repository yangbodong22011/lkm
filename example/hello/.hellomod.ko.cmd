cmd_/home/yangbodong/kernel/hello/hellomod.ko := ld -r -Map /var/tmp/hello.txt -T ./scripts/module-common.lds --build-id  -o /home/yangbodong/kernel/hello/hellomod.ko /home/yangbodong/kernel/hello/hellomod.o /home/yangbodong/kernel/hello/hellomod.mod.o
