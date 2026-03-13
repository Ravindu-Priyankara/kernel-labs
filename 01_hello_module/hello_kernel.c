// SPDX-License-Identifier: MIT

/*
* ================================================================
*  Module: hello_kernel.c
*
*  Description:
*  Simple Linux Kernel Module example that prints a message when
*  the module is loaded and unloaded.
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

#include <linux/module.h>  // need for every LKM
#include <linux/kernel.h>  // for this program this helps to get <linux/printk.h>
#include <linux/init.h>    // __init and __exit come from this header

/*
* ----------------------------------------------
* Module Metadata
* ----------------------------------------------
*/

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ravindu Priyankara");
MODULE_DESCRIPTION("Simple Hello Kernel Module");
MODULE_VERSION("1.0");

/*
* ----------------------------------------------
* Logging format prefix
* ----------------------------------------------
* Description:
*   - Helps to add text before log text
* Source location:
*   - include/linux/printk.h 
* ----------------------------------------------
*/

#define pr_fmt(fmt) "Kernel-Lab:" fmt

/*
* ----------------------------------------------
* Module Initialization
* ----------------------------------------------
* Description:
*   - Runs when the module is inserted into the kernel
* Source location:
*   - include/linux/init.h
* Arguments:
*   - 0 arguments
* Return:
*   - 0 = success
*   - negative on fail. {If a negative value is returned, module loading fails.}
* ----------------------------------------------
*/

static int __init hello_init(void){
    /*
    * -----------------------------------------------------------------------
    * important:
    *   - pr_info or other pr_* variants internally used printk.
    * Source location:
    *   - include/linux/printk.h
    * -----------------------------------------------------------------------
    */
    pr_info("Hello!\n");

    // printk does not use the pr_fmt prefix
    printk(KERN_INFO "Module loaded successfully!\n");

    return 0;
}

/*
* ----------------------------------------------
* Module Cleanup
* ----------------------------------------------
* Description:
*   - Runs when the module is removed
* Source location:
*   - include/linux/init.h
* Arguments:
*   - 0 arguments
* Return:
*   - no return
* ----------------------------------------------
*/

static void __exit hello_exit(void){
    pr_info("Goodbye, Module unloaded!\n");
}

/*
* -----------------------------------------------
* Register Init / Exit Functions
* -----------------------------------------------
* Description:
*   - Register the init and exit functions
* Source Location:
*   - include/linux/module.h
*/

module_init(hello_init);
module_exit(hello_exit);

/*
* -----------------------------------------------
* Expected Result!
* -----------------------------------------------
* Kernel-Lab:Hello!
* Module Loaded successfully!
* Kernel-Lab:Goodbye, Module unloaded!
* -----------------------------------------------
*/