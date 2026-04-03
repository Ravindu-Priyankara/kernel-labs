// SPDX-License-Identifier: GPL-2.0

/*
* ================================================================
*  Module: rodata_to_data.c
*
*  Description:
*  A simple Linux Kernel Module that store string .data section.
*
*  Author: Ravindu Priyankara
*  Project: Kernel Lab
*
*  Kernel Version: Tested on Linux 6.17.0-19-generic
*
*  ================================================================
*/

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ravindu Priyankara");
MODULE_DESCRIPTION("Simple Linux Kernel Module that store string .data section.");
MODULE_VERSION("1.0");

// stored .rodata
static char name[] = "Ravindu";

static __init int panic_init(void){
    pr_info("module loading...\n");
    pr_info("Before change name is: %s\n", name);
    name[0] = 'K';
    pr_info("changed...!\n");
    pr_info("After change name is: %s\n", name);

    return 0;
}

static __exit void panic_exit(void){
    pr_info("bye");
}

module_init(panic_init);
module_exit(panic_exit);