// SPDX-License-Identifier: GPL-2.0

/*
* ================================================================
*  Module: mod_param_int.c
*
*  Description:
*  Simple Linux Kernel Module example that gets an integer parameter.
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
#include <linux/errno.h>    // for error handling

/*
* ----------------------------------------------
* Module Metadata
* ----------------------------------------------
*/
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ravindu Priyankara");
MODULE_DESCRIPTION("Simple Linux Kernel Module that gets an integer parameter");
MODULE_PARM_DESC(data, "Integer value (0–1000)");
MODULE_VERSION("1.0");

/*
*   variable for pass integer
*   Size should be:
*       - <1000 and >= 0
*/
static int data = 0;

/*
*   module parameter
*   Usage:
*       module_param(name, type, perm)
*
*   @name: 
*       - variable name
*   @type:
*       - variable type
*   @perm:
*       - permission for parameter accessibility.
*
*   Defined in:
*       - include/linux/moduleparam.h
*
*   For access:
*       - ls /sys/module/<module name>/parameters/
*/
module_param(data, int, 0644);  // root can read and write, and others can read.

/*
*   Function for validate data
*   Arguments:
*       - integer parameter
*   Return:
*       - success = 0
*       - Failure = -EINVAL(-22)
*/
static int validate_the_data(int data){
    if(data > 1000 || data < 0 ){
        return -EINVAL;
    }

    return 0;
}

/*
*   Runs when the module is inserted into the kernel
*   Goals:
*       - validate the parameter value
*       - Log the parameter value
*   Arguments:
*       - 0 arguments
*   Return:
*       - 0 on success
*       - neggatives on failure
*/
static int __init param_init(void){
    pr_info("module loading......\n");

    // validate the parameter
    int ret = validate_the_data(data);
    if(ret){
        pr_err("invalid data value\n");
        return ret;
    }

    // log the data
    pr_info("module loaded successfully.\n");
    pr_info("parameter value is %d \n", data);

    return 0;
}

/*
*   Runs when the module is removed
*   Arguments:
*       - 0 arguments
*   Return:
*       - no return
*/
static void __exit param_exit(void){
    pr_info("unload the module\n");
}

/*
*   Register the init and exit functions
*/
module_init(param_init);
module_exit(param_exit);