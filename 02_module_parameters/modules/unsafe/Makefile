#files
obj-m += rodata_modify.o

#directories
KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

#bui;d the modules
all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

#clean
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean