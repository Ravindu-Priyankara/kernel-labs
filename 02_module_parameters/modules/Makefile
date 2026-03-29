#files
obj-m += mod_param_int.o mod_param_str.o

#directories
KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

#bui;d the modules
all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

#clean
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean