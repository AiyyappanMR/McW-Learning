## Day 4 - 23/02/26

Finished the software video series – felt good wrapping that up. Jumped straight into the activity: working with **SoundTouch** (audio tempo/pitch library) and **libopenshot** (video editing backend lib for OpenShot).

Real-world Git + build stuff today. Learned how these big C++ libs actually get cloned, configured, and compiled on my machine. CMake in a real large project is way different from tiny examples – it's the boss here.

### What I Did
1. **Cloned the repos**  
   ```bash
   git clone https://github.com/bilibili/soundtouch.git   # or whatever the fork/branch was
   git clone https://github.com/OpenShot/libopenshot.git
   ```

2. **Entered the dir & created build folder** (good practice to keep source clean)  
   ```bash
   cd libopenshot
   mkdir build && cd build
   ```

3. **CMake magic** – this generates the build system (Makefiles usually)  
   ```bash
   cmake ..                # or cmake -DCMAKE_BUILD_TYPE=Release ..
   cmake -DCMAKE_INSTALL_PREFIX=/usr/local ..   # if wanting to install system-wide
   ```
   Watched it detect dependencies, compilers, etc. It spits out a ton of config messages – first time seeing how many external libs these projects pull in (FFmpeg, Qt stuff for libopenshot, etc.).

4. **Built it**  
   ```bash
   make    
   ```

5. **Installed (optional, but did it to test)**  
   ```bash
    make install
   ```
   Copies headers + libs to prefix dirs so other projects can find them.

### Key Learnings
- **CMake is everywhere** in serious C++ projects. It handles platform differences, finds dependencies (like pkg-config for libs), generates build files. No more manual gcc commands for huge codebases.
- Git workflow felt natural now: clone → checkout branch if needed → work in build dir (out-of-source build is key!).
- Dependencies are a pain – had to install missing ones via apt (libavcodec-dev, etc. for libopenshot). CMake errors tell you exactly what's missing.
- SoundTouch was simpler (just audio processing), libopenshot is massive with video decoding/encoding – saw why OpenShot is powerful but complex.

