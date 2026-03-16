# How to install Linux Kernel Module

1. Compile the program
* For compile the program we should run this command.
```c
make
```

2. Install Module
* For install, we should use `kmod` package.
```c
sudo insmod hello_kernel.ko
```

3. Remove Module
* for remove module, we should use following command.
```c
sudo rmmod hello_kernel
```

4. Check module status
* To veryfy if your module is loaded
```c
lsmod | grep hello_kernel
```