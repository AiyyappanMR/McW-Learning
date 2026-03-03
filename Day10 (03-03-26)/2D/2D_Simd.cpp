#include <iostream>
#include <vector>
#include <chrono>
#include <immintrin.h>
#include <algorithm>

const int N = 1024;
typedef int (*Matrix2D)[N];

// 1. Scalar Transpose (2D Syntax)
void transpose_scalar(Matrix2D src, Matrix2D dst) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dst[j][i] = src[i][j];
        }
    }
}

// 2. AVX2 Half-Optimized Transpose (2D Syntax)
void transpose_avx2_half(Matrix2D src, Matrix2D dst) {
    int block = 8;
    for (int i = 0; i < N; i += block) {
        for (int j = 0; j < N; j += block) {
            for (int ii = i; ii < i + block && ii < N; ii++) {
                if (N - j >= 8) {
                    __m256i row = _mm256_loadu_si256((__m256i*)&src[ii][j]);
                    int temp[8];
                    _mm256_storeu_si256((__m256i*)temp, row);
                    for (int k = 0; k < 8; k++) dst[j + k][ii] = temp[k];
                } else {
                    for (int jj = j; jj < N; jj++) dst[jj][ii] = src[ii][jj];
                }
            }
        }
    }
}

// 3. Scalar Multiplication
void mat_mul_scalar(Matrix2D A, Matrix2D B, Matrix2D C) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int sum = 0;
            for (int k = 0; k < N; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

// 4. SIMD Multiplication (Basic)
void mat_mul_simd(Matrix2D A, Matrix2D B_T, Matrix2D C) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            __m256i v_sum = _mm256_setzero_si256();
            int k = 0;
            for (; k <= N - 8; k += 8) {
                __m256i vA = _mm256_loadu_si256((__m256i*)&A[i][k]);
                __m256i vB = _mm256_loadu_si256((__m256i*)&B_T[j][k]);
                v_sum = _mm256_add_epi32(v_sum, _mm256_mullo_epi32(vA, vB));
            }
            int temp[8];
            _mm256_storeu_si256((__m256i*)temp, v_sum);
            int row_sum = 0;
            for (int x = 0; x < 8; x++) row_sum += temp[x];
            for (; k < N; k++) row_sum += A[i][k] * B_T[j][k];
            C[i][j] = row_sum;
        }
    }
}

// 5. SIMD Multiplication (Tiled)
void mat_mul_simd_tiled(Matrix2D A, Matrix2D B_T, Matrix2D C) {
    const int TILE = 128;
    for (int it = 0; it < N; it += TILE) {
        for (int jt = 0; jt < N; jt += TILE) {
            for (int kt = 0; kt < N; kt += TILE) {
                for (int i = it; i < std::min(it + TILE, N); ++i) {
                    for (int j = jt; j < std::min(jt + TILE, N); ++j) {
                        __m256i v_sum = _mm256_setzero_si256();
                        int k = kt;
                        int k_end = std::min(kt + TILE, N);
                        for (; k <= k_end - 8; k += 8) {
                            __m256i vA = _mm256_loadu_si256((__m256i*)&A[i][k]);
                            __m256i vB = _mm256_loadu_si256((__m256i*)&B_T[j][k]);
                            v_sum = _mm256_add_epi32(v_sum, _mm256_mullo_epi32(vA, vB));
                        }
                        int temp[8];
                        _mm256_storeu_si256((__m256i*)temp, v_sum);
                        int t_sum = 0;
                        for (int x = 0; x < 8; x++) t_sum += temp[x];
                        for (; k < k_end; k++) t_sum += A[i][k] * B_T[j][k];
                        C[i][j] += t_sum;
                    }
                }
            }
        }
    }
}

bool verify(Matrix2D ref, Matrix2D target) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (ref[i][j] != target[i][j]) return false;
        }
    }
    return true;
}
int main() {
    auto A = new int[N][N];
    auto B = new int[N][N];
    auto B_T = new int[N][N];
    auto C_ref = new int[N][N];  
    auto C_test = new int[N][N]; 

    // Initialize data
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            A[i][j] = rand() % 10; 
            B[i][j] = rand() % 10;
            C_ref[i][j] = 0;
            C_test[i][j] = 0;
        }
    }

    // Exp 1: Scalar (The Gold Standard)
    auto t1 = std::chrono::high_resolution_clock::now();
    mat_mul_scalar(A, B, C_ref);
    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << "1. Scalar (Baseline):          " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << " ms | Status: REFERENCE\n";

    // Exp 2: SIMD + Scalar Transpose
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) C_test[i][j] = 0;
    auto t3 = std::chrono::high_resolution_clock::now();
    transpose_scalar(B, B_T);
    mat_mul_simd(A, B_T, C_test);
    auto t4 = std::chrono::high_resolution_clock::now();
    std::cout << "2. SIMD + Scalar Transpose:    " << std::chrono::duration_cast<std::chrono::milliseconds>(t4 - t3).count() << " ms | Status: " << (verify(C_ref, C_test) ? "PASS" : "FAIL") << "\n";

    // Exp 3: SIMD + AVX2 Transpose
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) C_test[i][j] = 0;
    auto t5 = std::chrono::high_resolution_clock::now();
    transpose_avx2_half(B, B_T);
    mat_mul_simd(A, B_T, C_test);
    auto t6 = std::chrono::high_resolution_clock::now();
    std::cout << "3. SIMD + AVX2 Transpose:      " << std::chrono::duration_cast<std::chrono::milliseconds>(t6 - t5).count() << " ms | Status: " << (verify(C_ref, C_test) ? "PASS" : "FAIL") << "\n";

    // Exp 4: SIMD + AVX2 Transpose + Tiling
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) C_test[i][j] = 0;
    auto t7 = std::chrono::high_resolution_clock::now();
    transpose_avx2_half(B, B_T);
    mat_mul_simd_tiled(A, B_T, C_test);
    auto t8 = std::chrono::high_resolution_clock::now();
    std::cout << "4. SIMD + Transpose + Tiling:  " << std::chrono::duration_cast<std::chrono::milliseconds>(t8 - t7).count() << " ms | Status: " << (verify(C_ref, C_test) ? "PASS" : "FAIL") << "\n";

    delete[] A; delete[] B; delete[] B_T; delete[] C_ref; delete[] C_test;
    return 0;
}