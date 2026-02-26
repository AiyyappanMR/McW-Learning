# Day 5 – 24/02/26

## How Compilers Actually Work

Today I understood that compilers do not “understand” code the way humans do. They mechanically translate high-level logic into instructions the CPU can blindly execute. The journey from C++ code to machine code happens in structured stages. First, the code is broken into tokens. Then it is parsed into an Abstract Syntax Tree, which represents the logical structure of the program. Semantic checks ensure types match and variables exist. Finally, code generation produces low-level machine instructions such as loading values into registers, performing arithmetic, and jumping based on conditions.

What felt powerful was realizing that even a simple loop in C++ turns into multiple low-level instructions like moves, comparisons, additions, and jumps. There is no intelligence in execution, just structured translation.

---

## Assembly Language Fundamentals

From the assembly video, I learned that assembly is simply a human-readable form of machine code, and it is specific to each CPU family because every processor follows its own Instruction Set Architecture. The CPU itself consists of registers for fast storage, an ALU for arithmetic, a program counter to track the next instruction, and RAM for code and data.

The example of implementing multiplication using repeated additions was eye-opening. If the instruction set does not provide a direct multiply operation, the processor simulates it using loops and basic arithmetic instructions. This showed me how primitive and mechanical computation is at the lowest level.

I also understood the build process more clearly: the assembler converts assembly into object files, the linker combines them with libraries into an executable, and the loader places it into memory for execution. Debug builds include extra information for stepping through code, while release builds remove overhead and aggressively optimize.

Learning assembly is important not just for curiosity but for understanding hardware behavior, debugging performance issues, writing drivers, bootstrapping new systems, and reverse engineering.

---

## Instruction Set Architecture and Design Philosophy

I explored the concept of Instruction Set Architecture, which defines the operations a CPU understands, the available registers, and the memory model. Compilers target a specific ISA when generating binary code.

I learned the difference between CISC and RISC architectures. CISC processors, like x86, support complex instructions and variable-length encoding, which can reduce instruction count but require more complex decoding. RISC processors, like ARM and RISC-V, use simpler and fixed-length instructions, enabling faster decoding and better energy efficiency. This explains why ARM dominates mobile devices while x86 remains strong in desktops and legacy systems.

Understanding ISA helped me connect how compilers optimize code differently depending on the target hardware and available instruction extensions.

---

## SIMD and Hardware-Level Parallelism

The concept of SIMD gave me a clearer picture of how processors achieve data-level parallelism. Instead of executing one operation on one value at a time, SIMD allows a single instruction to operate on multiple data elements simultaneously using wide registers. This is especially powerful for workloads involving vectors such as image processing, audio, and machine learning.

I learned that compilers can automatically vectorize loops in optimized builds if the data access pattern is suitable. However, in debug mode this optimization is often disabled. Developers can also manually use intrinsics for finer control. The Mandelbrot example made it clear how SIMD can process multiple pixels in parallel, though care must be taken to handle branches efficiently and ensure data is cache-friendly.

This showed me that performance gains are not only about multi-threading but also about exploiting hardware-level parallelism within a single core.
