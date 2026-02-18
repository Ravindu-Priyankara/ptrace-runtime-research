# ptrace-runtime-research

Research-driven exploration of Linux `ptrace`: process control,
runtime introspection, execution interruption, and forensic visibility.

## Why This Project

Most engineers use debuggers and tracing tools daily, but few explore
how process control works internally at the kernel boundary.

This repository documents a structured, experiment-based study of
Linux `ptrace`, focusing on:

- What actually happens when a process becomes traced
- How execution state changes during attach/detach
- How syscalls are intercepted
- How runtime behavior can diverge from static binaries
- What forensic artifacts ptrace introduces

## Research Approach

Each lab in this repository isolates one aspect of ptrace behavior.
Rather than building large tools, the goal is to:

- Minimize variables
- Observe kernel-visible state transitions
- Record behavioral changes
- Document unexpected findings

No obfuscation, no exploitation — only controlled experiments.


## Current Status
```
[x] 01_self_aware_process_under_ptrace
[x] 02_attach_and_dettach
[ ] 03_register_control  
[ ] 04_memory_introspection
[ ] 05_breakpoints 
[ ] 06_syscall_tracing
[ ] 07_runtime_mutation
[ ] 08_detection_artifacts
```

## Environment

- Linux (x86_64)
- GCC
- No external debugging libraries
- Direct syscall-level interaction

## Documentation Style

Each lab contains:
- A focused experiment
- Observations and timing notes
- Kernel-visible state changes
- Questions raised during testing

The goal is to think like a systems engineer, not just run code.

## Skills Demonstrated

- Linux process lifecycle understanding
- Signal and scheduler interaction awareness
- Syscall-level reasoning
- Debugger internals knowledge
- Forensic visibility analysis
- Controlled experimental methodology

## Future Exploration

- Interaction between ptrace and seccomp
- Multi-threaded tracing behavior
- eBPF vs ptrace comparison
- Performance impact measurement
