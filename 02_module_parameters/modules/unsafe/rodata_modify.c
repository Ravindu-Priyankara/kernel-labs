// SPDX-License-Identifier: GPL-2.0

/*
* ================================================================
*  Module: mod_param_str.c
*
*  Description:
* A simple Linux Kernel Module that crashes your kernel. | Do not run ....!
*
*  Important Notes:
*  - This program crashes your kernel because it tries to modify the .rodata section stored variable.
*
*  Purpose:
*  Learning what happens if u try to change a pointer that was stored via rodata.
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
#include <linux/kgdb.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ravindu Priyankara");
MODULE_DESCRIPTION("Simple Linux Kernel Module that panic your kernel.");
MODULE_PARM_DESC(name, "String value");
MODULE_VERSION("1.0");

// stored .rodata
static char *name = "Ravindu";

static __init int panic_init(void){
    kgdb_breakpoint();
    pr_info("module loading...\n");
    #ifdef UNSAFE 
        name[0] = 'K';  // crash{ try to modify .rodata stored string}
    #endif
    pr_info("changed...!\n");

    return 0;
}

static __exit void panic_exit(void){
    pr_info("bye");
}

module_init(panic_init);
module_exit(panic_exit);