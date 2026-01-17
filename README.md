# ASLR Exploration Lab: Understanding Memory Randomization in Linux

![Memory Layout Diagram](assets/memory-layout.png) <!-- Add a simple diagram via draw.io or similar -->

**Project Overview**  
As an Application Security Engineer, this medium-level lab demonstrates Address Space Layout Randomization (ASLR) in Linux. We build a simple C program to observe memory addresses (stack, heap, libc) with ASLR disabled/enabled, and test a buffer overflow that succeeds without ASLR but fails with it. This reinforces ASLR's role in mitigating memory corruption exploits (e.g., CWE-119/416).

**Key Learnings**  
- ASLR randomizes process memory (stack, heap, libraries) using kernel entropy.
- Config: `/proc/sys/kernel/randomize_va_space` (0=off, 1=partial, 2=full).
- Impact: Breaks predictable exploits like ROP chains.

**Tech Stack**  
- C (gcc), Bash scripts  
- Tools: gdb, /proc filesystem  
- OS: Ubuntu (VM on Mac)  
- Kernel: Linux 6.x+ (ASLR via CONFIG_RANDOMIZE_BASE)

## Setup Instructions  
1. **VM Lab**: Use Ubuntu 24.04 LTS in VirtualBox/Parallels on Mac.  
2. Install dependencies: `sudo apt update && sudo apt install build-essential gdb`.  
3. Clone this repo: `git clone https://github.com/YOUR-USERNAME/aslr-exploration-lab.git`.  
4. Build: `cd src && make`.  
5. Test: See [Testing ASLR](#testing-aslr) below.

## Testing ASLR  
- Disable: `sudo sysctl -w kernel.randomize_va_space=0`  
- Run: `./main` (observe fixed addresses)  
- Enable: `sudo sysctl -w kernel.randomize_va_space=2`  
- Analyze: `./analyze_addresses.sh` (logs randomization)

**Connect**: LinkedIn www.linkedin.com/in/utkarshpratap-cs | Built Jan 2026
