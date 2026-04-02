#files
obj-m += rodata_modify.o

#directories
KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)
UNSAFE ?= 0

#bui;d the modules
all:
	$(MAKE) -C $(KDIR) M=$(PWD) EXTRA_CFLAGS="-DUNSAFE=$(UNSAFE)" modules

#clean
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) UNSAFE clean

#for trigger crash
# make unsafe=1