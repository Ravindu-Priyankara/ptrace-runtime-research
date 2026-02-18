### Lab 01 – Self-Aware Process Under Tracing

A running process monitors its own execution state and reacts when a
tracer attaches or detaches.

Research focus:
- Detection via kernel-exposed metadata
- Execution pauses introduced by attach
- Timing anomalies and signal transitions
- Ownership boundaries enforced by the kernel