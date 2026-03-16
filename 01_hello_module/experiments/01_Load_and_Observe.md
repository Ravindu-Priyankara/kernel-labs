# Experiment 01 - Hello Kernel Module

## Objective

Understand how to create, compile, load and unload Linux Kernel Modules.

## Environment
- Kernel Version = `6.17.0-8-generic`
- OS : `Ubuntu 25.10`
- Architecture: `x86_64`

## Source code

`hello_kernel.c`
- Uses `module_init() and module_exit()`
- prints messages using `pr_info` && `printk`
- Set `pr_fmt` prefix

## Load the Module
```bash
sudo insmod hello_kernel.ko
```

- Check Kernel Log

<img src="./screenshot/load_the_module.png" width="600">

## Check the loaded module status

<img src="./screenshot/module_status.png" width="600">

## Unload the module

<img src="./screenshot/unload_the_module.png" width="600">

## Clear the diagnostic messages
```bash
sudo dmesg -C
```

## Observations

1. Kernel include timestamps in seconds since system boot.
2. `module_init` and `module_exit` control the module lifecycle.
3. `pr_fmt` prefix not effect to `printk`.

## Key Concepts Learned
- Linux Kernel Module structure
- logging
- module load/unload lifecycle