Operating System Lab (OS Lab) — Practical Manifest & Architecture
OS Kernel Language Compiler Author

This repository contains the comprehensive lab implementations, C programs, POSIX shell scripts, system call demonstrations, diagnostic traces, and execution output documentation for the Operating Systems Practical Laboratory Course.

It includes an Operating System Architecture Manifest, detailed experiment walkthroughs designed for classroom presentation, and a dedicated cross-disciplinary index detailing the practical experiments completed in Foundational Cyber Security (FOCS).

📑 Lab Manifest (Index of Experiments)
Exp #	Sub-Part	Date	Title / Topic	Primary Commands / System Calls	Key Artifacts
1	—	17-08-2026	Virtualization & Ubuntu OS Setup	VirtualBox, ISO mounting, VM resource allocation	Experiment 1, Experiment 1 outputs.pdf
2	(a)	19-08-2026	Working with Basic Bash Commands	pwd, ls, cd, mkdir, rmdir, rm, touch	Experiment 2(a)
2	(b)	19-08-2026	Flowchart-Based Directory Hierarchy	mkdir -p, multi-level hierarchy (Sem_3/OS/...)	Experiment 2(b), Experiment 2(b) outputs .pdf
3	(a)	24-08-2026	Command Chaining & Output Redirection	date; w | cat > who.txt, pipelines, redirection	Experiment 3(a), Experiment 3(a) output .pdf
3	(b)	24-08-2026	Stream Text Transformation with Sed	sed -i 's/^ \([^ ]*\) \(.*\)$/\2 \1/'	Experiment 3 (b), experiment 3(b) outputs .pdf
4	—	31-08-2026	Process Management & Linux Text Editors	ps aux, top, pgrep, kill, &, jobs, nano, vi	Experiment 4, Experiment 4 outputs .pdf
5	(a)	07-09-2026	File vs Directory Classifier Script	[ -f "$1" ], [ -d "$1" ], positional parameters	exp5a.sh, Experiment 5(a) outputs .pdf
5	(b)	09-09-2026	Filename Uppercase Converter Script	tr '[:lower:]' '[:upper:]', mv, command substitution	exp5b.sh, Experiment 5(b) outputs.pdf
6	(a)	13-09-2026	User Session Duration & Login Tracker	who, awk, string matching (-z), interactive input	exp6a.sh, Experiment 6(a) output .pdf
6	(b)	13-09-2026	Line Range Extractor Script	sed -n "${start},${end}p"	exp6b.sh, Experiment 6(b) output .pdf
6	(c)	13-09-2026	Multi-File Word Deletion Script	sed -i "/$word/d", variadic script arguments "$@"	exp6c.sh, Experiment 6(c) output .pdf
7	—	Sept 2026	String Operations & Benchmarking (C vs Shell)	fgets, gcc, string parsing, time ./program	exp7.c, exp7.sh, outputs.pdf
8	—	28-09-2026	Dynamic Memory Allocation & Monitoring	malloc(), free(), signal(SIGINT), free -h, ps aux	exp8.c, Experiment 8 outputs .pdf
9	—	01-11-2026	CPU-Bound vs I/O-Bound Scheduling Analysis	top, pmap -x <PID>, background execution (&)	cpu.c, io.c, Screenshots.pdf
10	—	01-11-2026	Process Creation & Synchronization	fork(), getpid(), wait(NULL), sleep(), exit()	exp10.c, Screenshots.pdf
🏛️ Operating System Architecture Overview
The lab exercises progress systematically through the core subsystems of a modern operating system:


Detailed Architecture Reference: For deeper diagrams and sequence flows of process state transitions, virtual address layout (pmap), and memory paging, see ARCHITECTURE.md.

🔬 Detailed Experiment Walkthroughs
Experiment 1: Virtualization & Ubuntu OS Setup
Objective: Deploy and configure a virtualized Linux development environment.
Methodology: Setup Oracle VirtualBox (Type-2 Hypervisor), allocate virtual hardware resources (RAM, CPU cores, dynamically allocated virtual disk), mount the Ubuntu 64-bit desktop ISO image, and configure root/user partitions.
Key Concepts: Hypervisor architecture, virtual machines, kernel boot sequence, user privilege configuration.
Experiment 2: Linux Shell Fundamentals & Directory Management
Part (a) — Core Bash Commands:
Directory Navigation: pwd -P, pwd -L, cd .., cd ~, cd <dir>.
Directory Listing: ls -l (detailed permissions/ownership), ls -a (hidden entries), ls -lt (sorted by modification time).
Creation & Deletion: mkdir -p (hierarchical creation), rmdir -p, rm -rf, touch (timestamps and file instantiation).
Part (b) — Flowchart-Based Hierarchical Organization:
Implemented the semester academic directory structure:
Sem_3/
├── COA/    ── [ Practical | Theory ]
├── HSMC/   ── [ Book | Class ]
├── OS/     ── [ Theory | Lab ]
└── cyber/  ── [ Lab | Theory ]
Experiment 3: I/O Redirection & Stream Text Processing
Part (a) — Sequential Command Chaining & Redirection:
Executed: date; w | cat > who.txt
Demonstrates command sequencing via ;, standard pipeline execution via |, and file descriptor stdout redirection (>) to capture active session telemetry.
Part (b) — Stream Transformation using Sed:
Executed: sed -i 's/^\([^ ]*\) \(.*\)$/\2 \1/' name.txt
Uses POSIX regular expressions with capture groups \1 and \2 to swap first and last words across every record in-place (-i).
Experiment 4: Process Management & Editor Mastery
Process Inspection:
ps (terminal session processes), ps aux (global system processes with user/CPU/memory telemetry), top (dynamic real-time process monitoring).
Process Signaling & Job Control:
pgrep <name> to resolve Process IDs.
kill <PID> to issue software termination signals.
Appending & to run processes asynchronously in the background; jobs and fg to manage the process job queue.
Text File Editing: File creation, editing, and modal operation in nano and vi/vim.
Experiment 5: Shell Scripting — Conditional Branching & String Transformation
Part (a) — File Type Classifier (exp5a.sh):
Accepts a path argument ($1) and evaluates filesystem status using test conditions:
if [ -f "$1" ]; then echo "$1 is a file";
elif [ -d "$1" ]; then echo "$1 is a directory";
else echo "$1 does not exist"; fi
Part (b) — Uppercase Filename Translation (exp5b.sh):
Translates lowercase filename strings to uppercase using character substitution:
mv "$1" "$(echo "$1" | tr '[:lower:]' '[:upper:]')"
Experiment 6: User Tracking & Stream Operations
Part (a) — User Login Duration Tracker (exp6a.sh):
Interactively queries user presence and parses login timestamps from who using awk:
login_time=$(who | awk -v u="$user" '$1 == u {print $3, $4; exit}')
Part (b) — Specific Line Range Extraction (exp6b.sh):
Extracts line ranges [start, end] from target files using sed -n "${start},${end}p" "$file".
Part (c) — Variadic Word Removal Script (exp6c.sh):
Traverses an arbitrary argument list of filenames ("$@") and purges lines containing target words via sed -i "/$word/d" "$file".
Experiment 7: String Operations & Performance Benchmarking (C vs Shell)
Objective: Compare runtime performance and algorithmic efficiency between compiled native binary code (exp7.c) and interpreted shell execution (exp7.sh).
Operations: String length computation and substring slicing.
Benchmarking via time Command:
Compiled C (./string): Execution completed with near-instantaneous CPU time (user: 0.001s, sys: 0.001s).
Shell Script (./exp7.sh): Incurred higher execution latency due to subshell forks and bash interpreter overhead.
Experiment 8: Dynamic Memory Allocation & Linux Memory Telemetry
Source: exp8.c
Mechanism:
Accepts allocation volume in Megabytes via CLI argument (argv[1]).
Allocates dynamic memory on the heap using malloc(bytes).
Writes to memory pages in 4 KB strides to trigger Minor Page Faults, ensuring physical frame backing in Resident Set Size (RSS).
Intercepts the SIGINT signal (Ctrl+C) via signal(SIGINT, handle_sigint).
Monitored through free -h and ps aux | grep exp8.
On termination, explicitly deallocates memory via free() to prevent resource leaks.
Experiment 9: CPU-Bound vs I/O-Bound Scheduling & Memory Mapping
Sources: cpu.c, io.c
Comparative Analysis:
cpu.c: Infinite mathematical loop launched in background (./cpu &). top verifies ~99.7% CPU utilization in Running (R) state.
io.c: Sleep/I/O cycle process launched in background (./io &). top verifies ~0.4% CPU utilization in Sleeping (S) state.
Virtual Memory Mapping via pmap -x <PID>:
Examined the exact virtual address map of both processes:
Text and Read-Only Data (r-xp, r--p)
Dynamic Heap Segment ([heap], rw-p)
Shared C Library mappings (libc.so.6)
Process Stack ([stack])
Kernel Auxiliary Pages ([vvar], [vdso], [vsyscall])
Experiment 10: Process Creation & Synchronization with POSIX System Calls
Source: exp10.c
System Call Workflow:
fork(): Creates a new child process by cloning the parent's address space and PCB.
Evaluates return code:
p == 0: Executes child routine, displays child PID via getpid(), sleeps 2 seconds, and calls exit(0).
p > 0: Executes parent routine, prints parent PID, and invokes wait(NULL).
wait(NULL) blocks parent execution until the child terminates, preventing zombie process accumulation and ensuring orderly kernel resource reclamation.
🛡️ Foundational Cyber Security (FOCS) Lab Manifest
The operating system's internal architectures (process isolation, stack/heap layout, kernel networking, and system calls) provide the direct foundation for cyber security. Below is the manifest of practical security experiments completed in conjunction with this course:

Exp #	Experiment Title	Security Domain	Tools / Environment	Core Cyber Security Mechanism
1	Information Gathering via Google Dorking	Reconnaissance / OSINT	Google Search Engine	Advanced search operators (site:, filetype:, inurl:, intitle:) to locate exposed credentials and vulnerable endpoints.
2	Buffer Overflow Vulnerability & Mitigation	Binary Exploitation	C, GCC (-fno-stack-protector)	Corrupting stack memory by exceeding array bounds; overwriting the instruction pointer (EIP/RIP); studying stack canaries and ASLR.
3	Host Scanning & Network Reconnaissance	Network Security	Nmap, Ncat, CLI	Active host discovery, TCP SYN scanning (-sS), service version detection (-sV), and port identification.
4	Packet Capturing & Protocol Analysis	Traffic Analysis	Wireshark, Pcap	Capturing raw Ethernet frames, analyzing 3-way handshakes (SYN, SYN-ACK, ACK), inspecting unencrypted plaintext protocols (HTTP, DNS).
5	Password Security: Brute Force & Dictionary Attacks	Authentication Security	Kali Linux, Hydra	Automated dictionary credential guessing against authentication services; analyzing password entropy and lockout mitigations.
6	MD5 Data Transformation & Processing	Cryptology	Cryptography Virtual Lab	Simulating 512-bit block transformations, 4 round operations, and padding schemes in the MD5 message-digest algorithm.
7	Properties of Cryptographic Hash Functions	Applied Cryptography	Hash Simulators / Browser	Demonstrating the Avalanche Effect, pre-image resistance, second pre-image resistance, and collision resistance in SHA/MD5 families.
8	Network Intrusion Detection System (NIDS)	Defense & Monitoring	Kali Linux, Snort 3	Writing custom detection rules (local.rules) for ICMP echo traffic; validating rule syntax; capturing test pings and analyzing intrusion alert logs.
The OS-Security Correlation
Buffer Overflow (FOCS Exp 2) ↔ Memory Architecture (OS Exp 8 & 9): Demonstrates why the boundary between stack, heap, and instruction memory must be enforced by OS hardware paging (NX bit, ASLR).
Intrusion Detection (FOCS Exp 8) ↔ Network & System Calls (OS Exp 3 & 4): Demonstrates how network interfaces operate in promiscuous mode at the kernel driver layer to feed packet capture engines without disrupting standard host communications.
🚀 How to Compile and Execute
Prerequisites
A Linux environment (Ubuntu 20.04/22.04/24.04 or Debian) with GCC and Bash:

sudo apt update
sudo apt install build-essential gcc procps pmap -y
1. Running Shell Script Experiments
# Experiment 5(a)
chmod +x "Experiment 5/exp5a.sh"
./"Experiment 5/exp5a.sh" "Experiment 5/exp5a.sh"

# Experiment 6(b)
chmod +x "Experiment 6/exp6b.sh"
./"Experiment 6/exp6b.sh"
2. Compiling and Running C Programs
# Experiment 7: String Operations & Benchmarking
gcc "Experiment 7/exp7.c" -o string_c
time ./string_c

# Experiment 8: Memory Allocation & Signal Handling
gcc "Experiment 8/exp8.c" -o exp8
./exp8 100
# In another terminal: free -h; ps aux | grep exp8
# Press Ctrl+C to release and exit cleanly

# Experiment 9: CPU vs I/O Bound Processes
gcc "Experiment 9/cpu.c" -o cpu
gcc "Experiment 9/io.c" -o io
./cpu &
./io &
top
pmap -x <PID>
killall cpu io

# Experiment 10: Fork and Process Synchronization
gcc "Experiment 10/exp10.c" -o exp10
./exp10
📁 Repository Structure
Operating-System-Lab/
├── ARCHITECTURE.md                                     # System architecture, process lifecycles & memory models
├── README.md                                           # Comprehensive lab manifest & classroom presentation guide
├── .gitignore                                          # Build artifacts and executable filter
├── Experiment 1/
│   ├── Experiment 1                                    # VirtualBox & Ubuntu installation guide
│   └── Experiment 1 outputs.pdf                        # Setup & execution screenshots
├── Experiment 2/
│   ├── Experiment 2(a)                                 # Basic Bash commands reference
│   ├── Experiment 2(b)                                 # Directory tree commands
│   └── Experiment 2(b) outputs .pdf                    # Terminal directory outputs
├── Experiment 3/
│   ├── Experiment 3(a)                                 # Sequential execution & pipe redirection
│   ├── Experiment 3(a) output .pdf                     # Execution verification PDF
│   ├── Experiment 3 (b)                                # Sed word swap command
│   └── experiment 3(b) outputs .pdf                    # Sed execution screenshots
├── Experiment 4/
│   ├── Experiment 4                                    # Process control commands & Vi/Nano
│   └── Experiment 4 outputs .pdf                       # Process management outputs
├── Experiment 5/
│   ├── Experiment 5(a)                                 # File vs directory algorithm
│   ├── exp5a.sh                                        # Standalone executable shell script
│   ├── Experiment 5(a) outputs .pdf                    # Execution screenshots
│   ├── Experiment 5(b)                                 # Filename uppercase algorithm
│   ├── exp5b.sh                                        # Standalone executable shell script
│   └── Experiment 5(b) outputs.pdf                     # Execution screenshots
├── Experiment 6/
│   ├── Experiment 6(a)                                 # User login tracking procedure
│   ├── exp6a.sh                                        # Standalone executable shell script
│   ├── Experiment 6(a) output .pdf                     # Execution screenshots
│   ├── Experiment 6(b)                                 # Line range display procedure
│   ├── exp6b.sh                                        # Standalone executable shell script
│   ├── Experiment 6(b) output .pdf                     # Execution screenshots
│   ├── Experiment 6(c)                                 # Word deletion procedure
│   ├── exp6c.sh                                        # Standalone executable shell script
│   └── Experiment 6(c) output .pdf                     # Execution screenshots
├── Experiment 7/
│   ├── Experiment 7                                    # String operation algorithms & timing
│   ├── exp7.c                                          # C program implementation
│   ├── exp7.sh                                         # Shell script implementation
│   └── Experiment 7 outputs .pdf                       # Comparative execution outputs
├── Experiment 8/
│   ├── Experiment 8                                    # Memory allocation documentation
│   ├── exp8.c                                          # Dynamic memory & SIGINT C code
│   └── Experiment 8 outputs .pdf                       # Memory monitoring screenshots
├── Experiment 9/
│   ├── Experiment 9                                    # Lab writeup reference
│   ├── Experiment 9 CPU vs IO Bound Analysis.md        # Comprehensive experiment analysis
│   ├── cpu.c                                           # CPU-intensive benchmark program
│   ├── io.c                                            # I/O-intensive benchmark program
│   └── Experiment 9 Screenshots & Execution.pdf        # Top & pmap telemetry outputs
└── Experiment 10/
    ├── Experiment 10                                   # Lab writeup reference
    ├── Experiment 10 Process Management.md             # Fork & synchronization analysis
    ├── exp10.c                                         # Fork, getpid, wait, exit C code
    └── Experiment 10 Screenshots & Execution.pdf       # Process execution screenshots
👨‍💻 Author & Academic Attribution
Author: Mirza Younis Hussain
Profile: @MirzaYounisHussain
Repository: Operating-System-Lab
