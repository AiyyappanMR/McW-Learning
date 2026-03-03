#include <iostream>
#include <immintrin.h> 

int main()
{
    int n = 0;
    std::cout << "Enter a len of N: ";
    std::cin >> n;

    int* A = new int[n];
    int* B = new int[n];
    int* mulOut = new int[n];
    int* divOut = new int[n];

    for (int i = 0; i < n; i++) {
        std::cout << "Enter a A[" << i << "]: ";
        std::cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        std::cout << "Enter a B[" << i << "]: ";
        std::cin >> B[i];
    }

    int i = 0;
    for (; i <= n - 8; i += 8)
    {
        __m256i vA = _mm256_loadu_si256((__m256i*)&A[i]);
        __m256i vB = _mm256_loadu_si256((__m256i*)&B[i]);
        __m256i mul = _mm256_mullo_epi32(vA, vB);
        _mm256_storeu_si256((__m256i*)&mulOut[i], mul);

        __m256 fA = _mm256_cvtepi32_ps(vA);
        __m256 fB = _mm256_cvtepi32_ps(vB);
        __m256 fDiv = _mm256_div_ps(fA, fB);
        __m256i div = _mm256_cvtps_epi32(fDiv);
        _mm256_storeu_si256((__m256i*)&divOut[i], div);
    }

    for (; i < n; i++)
    {
        mulOut[i] = A[i] * B[i];
        if (B[i] != 0) {
            divOut[i] = A[i] / B[i];
        } else {
            divOut[i] = 0; 
        }
    }

    std::cout << "Mul: ";
    for (int i = 0; i < n; i++) std::cout << mulOut[i] << " ";
    
    std::cout << "\nDiv: ";
    for (int i = 0; i < n; i++) std::cout << divOut[i] << " ";

    delete[] A; delete[] B; delete[] mulOut; delete[] divOut;
    return 0;
}