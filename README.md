# Kernel Labs

A collection of Linux kernel module experiments exploring Linux internals, process monitoring, and runtime observability.

This repository is meant to demonstrate applied kernel knowledge, from basic modules to process and network monitoring experiments.

## Structure

- `01_hello_module` – basic kernel module example
- `02_module_parameters` – experiment with module parameters
- `03_process_tree` – explore parent/child/sibling processes
- `04_zombie_detector` – detect zombie processes
- `05_orphan_detector` – detect orphaned processes
- `06_exec_monitor` – monitor execve events
- `07_reverse_shell_demo` – proof-of-concept reverse shell detection

## Goals

- Learn Linux kernel internals
- Explore `task_struct` and process lifecycle
- Build understanding of kernel-level security monitoring
- Bridge user-space behavior with kernel-space observability

## Notes

- Experiments should be run in a VM for safety.
- This is a **learning-focused repository**, not production code.
- eBPF experiments complement these kernel modules for safe runtime monitoring.

---