#object file name
obj-m += hello_kernel.o

# build the module
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

#clean
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean