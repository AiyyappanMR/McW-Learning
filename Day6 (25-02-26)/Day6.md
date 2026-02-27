## Day 6 – 25/02/26  
**Rethinking CPU Performance**

Today I reshaped my understanding of CPU performance. Earlier, I believed that higher gigahertz automatically meant a faster processor. Now I clearly understand that real performance depends on how much useful work is completed in each cycle, which is determined by **Instructions Per Cycle (IPC)**. Clock speed only tells me how fast the processor ticks, but IPC tells me how productive each tick is. I now see why newer processor architectures outperform older ones even at the same frequency — they are designed to execute more instructions per cycle using smarter pipelines, better branch prediction, improved execution units, and more efficient cache systems.

**Understanding Memory-Bound Performance**

Another major realization was about memory-bound performance. I used to wonder how a powerful CPU could still perform poorly. Now I understand that when the processor constantly waits for data from main memory, it becomes stalled, and its execution units sit idle. In such cases, the bottleneck is not computation but memory access. This helped me connect CPU performance directly with memory hierarchy behavior.

**Importance of Cache and Locality**

I learned that data is fetched in cache lines, and the way a program accesses memory significantly affects performance. If the same data is reused quickly, **temporal locality** keeps it in cache. If nearby data is accessed sequentially, **spatial locality** ensures it is already loaded. Good locality reduces cache misses, which reduces pipeline stalls, which ultimately increases IPC and overall throughput. This made me realize that performance optimization is often about improving data access patterns rather than increasing processor speed.

**SIMD and Vectorization**

I also explored SIMD and compiler vectorization. I learned that modern processors can execute a single instruction on multiple data elements simultaneously, giving large speedups in workloads like audio processing, image operations, and machine learning. Initially, I did not understand how the compiler decides when to apply this optimization. Now I know it analyzes loops for independence, predictable memory access, and absence of data dependencies. If the structure is suitable and the hardware supports it, the compiler automatically transforms scalar operations into parallel vector instructions. This showed me that writing vector-friendly code is an important part of performance engineering.  