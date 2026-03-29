// SPDX-License-Identifier: GPL-2.0

/*
* ================================================================
*  Module: mod_param_str.c
*
*  Description:
*  Simple Linux Kernel Module example that gets string parameter.
*
*  Important Notes:
*  - This parameter restricts access outside of this module. The reason is that this module's goal isn't testing concurrency.
*
*  Purpose:
*  Learning Linux Kernel Module (LKM) development fundamentals.
*
*  Author: Ravindu Priyankara
*  Project: Kernel Lab
*
*  Kernel Version: Tested on Linux 6.17.0-8-generic
*
*  ================================================================
*/

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

/*
*   |-------------------------|
*   |   Module Metadata       |
*   |-------------------------|
*/

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ravindu Priyankara");
MODULE_DESCRIPTION("Simple Linux Kernel Module that gets a string parameter");
MODULE_PARM_DESC(name, "String value");
MODULE_VERSION("1.0");

/*
*   Variable for pass string value.
*
*   Important Note:
*       - THis variable use as read only.
*       - And also this will be located on .rodata section because of this read only.
*/
static char *name = "Ravindu";

/*
*   Important Note:
*       - charp is moduleparam.h defined macro.
*       - no sysfs file created
*/
module_param(name, charp, 0000);

/*
*   Init function
*   0 Arguments
*   Return:
*       - 0 in success and negative on error
*/
static __init int param_init(void){
    pr_info("module loading....\n");
    pr_info("Name is %s \n", name);
    
    return 0;
}

/*
*   Exit function
*   0 Arguments
*   no return
*/
static __exit void param_exit(void){
    pr_info("module unloaded!....\n");
}

// register the init and exit
module_init(param_init);
module_exit(param_exit);