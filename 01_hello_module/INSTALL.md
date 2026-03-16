# How to install Linux Kernel Module

1. Compile the program
* For compile the program we should run this command.
```bash
make
```

2. Install Module
* For install, we should use `kmod` package.
```bash
sudo insmod hello_kernel.ko
```

3. Remove Module
* for remove module, we should use following command.
```bash
sudo rmmod hello_kernel
```

4. Check module status
* To veryfy if your module is loaded
```bash
lsmod | grep hello_kernel
```