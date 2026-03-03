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
    for (int i = 0; i < n; i++)
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