# General Information

## Objective

Understand how to pass arguments to a Linux Kernel Module.

## Environment
- Kernel Version = `6.17.0-8-generic`
- OS : `Ubuntu 25.10`
- Architecture: `x86_64`

## Module Parameter Defined In:

`include/linux/moduleparam.h`

## Common Permissions used for parameters

| Permission | Meaning |
|------------|---------|
| 0 | Not visible in sysfs |
| 0444 | read only (everyone can read) |
| 0644 | root can write and everyone can read |
| 0600 | only root can read write. |
|------|---------------------------|


