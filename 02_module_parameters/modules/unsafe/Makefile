# files
obj-m += rodata_modify.o

# directories
KDIR := /lib/modules/$(shell uname -r)/build
PWD  := $(shell pwd)

UNSAFE ?= 0

# flags
ccflags-y += -Wall -Wextra

ifeq ($(UNSAFE),1)
ccflags-y += -DUNSAFE=1
endif

# build
all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

# clean
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean