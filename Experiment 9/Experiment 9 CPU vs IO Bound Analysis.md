Experiment 9: CPU-Bound vs I/O-Bound Process Performance & Memory Mapping Analysis
Date: 01-11-2026
Environment: Ubuntu Linux (x86_64) / GCC

Aim
To study, implement, and compare the execution characteristics of a CPU-bound process and an I/O-bound process, and analyze their virtual address space layout using Linux process diagnostic utilities (top and pmap -x).

Theoretical Background
CPU-Bound Process:

A process whose execution speed is primarily limited by the processor's clock speed.
It performs intensive mathematical or iterative computations with minimal I/O operations.
When scheduled, it monopolizes its time quantum and exhibits ~100% CPU utilization.
I/O-Bound Process:

A process that spends the majority of its lifecycle waiting for input/output operations, system timers, or interrupts (e.g., disk I/O, network sockets, sleep()).
Its CPU utilization remains near 0%, frequently relinquishing the CPU to the OS scheduler.
Memory Mapping (pmap):

In Linux, every process is allocated a Virtual Memory space containing text (code), data, heap, dynamically linked shared libraries (e.g., libc.so), stack, and kernel-mapped pages (vvar, vdso, vsyscall).
pmap -x <PID> outputs the resident set size (RSS), dirty pages, and mapping boundaries for each segment.
Source Code
1. CPU-Bound Implementation (cpu.c)
#include <stdio.h>

int main()
{
    printf("CPU-bound process started. Consuming CPU cycles...\n");
    volatile unsigned long long counter = 0;
    while (1) {
        counter++;
    }
    return 0;
}
2. I/O-Bound Implementation (io.c)
#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("I/O-bound process started. Sleeping in loop...\n");
    while (1) {
        sleep(1);
    }
    return 0;
}
Compilation & Execution Steps
# 1. Compile both C programs
gcc cpu.c -o cpu
gcc io.c -o io

# 2. Launch CPU-bound process in background
./cpu &
# Process launched with PID (e.g., 6274)

# 3. Monitor CPU utilization
top
# Observation: PID 6274 shows ~99.7% %CPU

# 4. Inspect memory map of CPU-bound process
pmap -x 6274

# 5. Launch I/O-bound process in background
./io &
# Process launched with PID (e.g., 6351)

# 6. Monitor CPU utilization
top
# Observation: PID 6351 shows ~0.4% %CPU

# 7. Inspect memory map of I/O-bound process
pmap -x 6351

# 8. Terminate background processes
kill 6274 6351
Observations & Output Summary
Metric	CPU-Bound (cpu)	I/O-Bound (io)
Process State in top	R (Running)	S (Sleeping / Waiting)
%CPU Utilization	99.7%	0.4%
Memory Mapped (total kB)	~2568 kB	~2568 kB
Resident Set Size (RSS)	~324 kB	~324 kB
Key Segments Mapped	Text, Data, Heap, Stack, libc.so, vdso	Text, Data, Heap, Stack, libc.so, vdso
Result
Successfully observed the contrasting resource consumption behavior between CPU-bound and I/O-bound processes using top, and verified their address space layout and memory mappings using pmap -x.
