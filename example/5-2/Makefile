WFLAGS := -Wall -Wstrict-prototypes -Wno-trigraphs
LDFLAGS := -Map /var/tmp/printpid.txt
EXTRA_CFLAGS := $(WFLAGS)
EXTRA_CFLAGS += -D_DEBUG -g3 -fno-stack-protector
MODULE = printpidmod
obj-m := $(MODULE).o
all:
	make -C /lib/modules/$(shell uname -r)/build SUBDIRS=$(shell pwd) modules
$(MODULE)-objs := printpid.o

clean:
	rm -rf *.o *~ .*.cmd *.ko *.mod.c *.order *.symvers *.tmp_version built-in.o

