# Module Architecture – `mod_param_int`

**Purpose:** Understanding how a Linux Kernel Module (LKM) is loaded, represented, and exposed via sysfs.

---

## 1. Overview

When a kernel module (`.ko`) is loaded:

```text
Kernel Module (.ko)
    ↓
Kernel Memory
    ↓
/sys/module/<module_name>/  (sysfs representation)
```

* Kernel tracks the module’s state, memory, parameters, and dependencies.
* sysfs exposes this info for inspection, debugging, and management.

---

## 2. Key `/sys/module/<module_name>/` entries

| File/Dir      | Description                                                    |
| ------------- | -------------------------------------------------------------- |
| `coresize`    | Module footprint in kernel memory (code + data)                |
| `initsize`    | Size of `__init` section (freed after init)                    |
| `initstate`   | Module state: `live`, `coming`, `going`                        |
| `refcnt`      | Reference count (how many users depend on the module)          |
| `srcversion`  | Hash of module source code                                     |
| `taint`       | Flags marking module state (`O` = out-of-tree, `E` = unsigned) |
| `uevent`      | Event info sent to user-space (used by `udev`)                 |
| `version`     | Module version (`MODULE_VERSION`)                              |
| `holders/`    | Modules that depend on this module                             |
| `parameters/` | Module parameters exposed via `module_param()`                 |
| `sections/`   | Memory sections in kernel (conceptual info)                    |
| `notes/`      | ELF notes section (rarely used manually)                       |

---

## 3. Parameters (`module_param`)

* `module_param(data, int, 0644)` creates:

  * A sysfs file: `/sys/module/mod_param_int/parameters/data`
  * Linked to kernel memory variable
  * Permission controls read/write access
* Example usage:

```bash
cat /sys/module/mod_param_int/parameters/data   # read
echo 42 | sudo tee /sys/module/mod_param_int/parameters/data  # write (if permissions allow)
```

---

## 4. Sections (conceptual, safe to share)

| Section                        | Purpose                                  |
| ------------------------------ | ---------------------------------------- |
| `__param`                      | Memory section holding module parameters |
| `__mcount_loc`                 | Function tracing / profiling hooks       |
| `__patchable_function_entries` | Live patching / ftrace runtime hooks     |


---

## 5. Workflow – How LKM interacts with sysfs

1. Module is loaded via `insmod` → allocated in kernel memory
2. `module_param()` registers parameters → linked to sysfs
3. Kernel exposes:

   * parameters (`/parameters`)
   * metadata (`/version`, `/taint`, `/refcnt`)
4. sysfs allows safe user-space access to read/write values
5. Module can be removed (`rmmod`) once `refcnt` = 0


---
