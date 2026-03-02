#include <iostream>
#include <immintrin.h> 
#include <vector>

int main()
{
    int n=0;
    std::cout << "Enter a len of N: ";
    std::cin >> n;
    int* A = new int[n];
    int* B = new int[n];
    int* sumOut = new int[n];
    int* subOut = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter a A[" << i << "]: ";
        std::cin >> A[i];
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter a B[" << i << "]: ";
        std::cin >> B[i];
    }

    int i = 0;
    for (;i< n-8; i++)
    {
        __m256i vA = _mm256_loadu_si256((__m256i*)&A[i]);
        __m256i vB = _mm256_loadu_si256((__m256i*)&B[i]);
        __m256i sum = _mm256_add_epi32(vA, vB);
        __m256i sub = _mm256_sub_epi32(vA, vB);
        _mm256_storeu_si256((__m256i*)&sumOut[i], sum);
        _mm256_storeu_si256((__m256i*)&subOut[i], sub);
    }

    for (; i < n; i++)
    {
        sumOut[i] = A[i] + B[i];
        subOut[i] = A[i] - B[i];
    }
    
    std::cout << "Sum: ";
    for (int i = 0; i < n; i++){
        std::cout << sumOut[i] << " ";
    }
    std::cout << "\nSub: ";
    for (int i = 0; i < n; i++){
        std::cout << subOut[i] << " ";
    }
}