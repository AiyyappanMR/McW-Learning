# Conv1D and Conv2D Implementation in C++

Custom implementation of 1D and 2D convolution operations in C++,
validated against PyTorch's functional conv1d and conv2d outputs
using Google Test.

---

## Project Structure
```
Day13 (11-03-26)/
├── include/
│   └── conv.hpp          # Function declarations
├── src/
│   └── conv.cpp          # Conv1D and Conv2D implementation
├── test/
│   └── test_script.cpp   # Parameterized GTest validation
└── CMakeLists.txt
```

---

## Implementation Details

### Conv1D
- Input  : `num_channels x input_length` matrix
- Kernel : per-channel kernel where `kernel[channel][k] = channel + 1`
- Output : `(input_length - kernel_size) / stride + 1` elements
- Slides kernel across input width, accumulates across all channels

### Conv2D
- Input  : `input_height x input_width` single-channel matrix
- Kernel : 2D kernel where `kernel[row][col] = row + col`
- Output : `(H - kH) / stride + 1  x  (W - kW) / stride + 1` matrix
- Slides kernel across both height and width dimensions

---

## Dependencies

- [LibTorch](https://pytorch.org/cppdocs/) — PyTorch C++ API
- [Google Test](https://github.com/google/googletest) — Unit testing framework
- CMake >= 3.10
- C++17 or higher

---

## How to Build and Run

### Step 1 — Create build directory
```bash
cd "Day13 (11-03-26)"
mkdir build && cd build
```

### Step 2 — Configure with CMake
```bash
cmake ..
```

### Step 3 — Build
```bash
make
```

### Step 4 — Run tests
```bash
./Validation
```

---