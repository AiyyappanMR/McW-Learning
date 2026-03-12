#ifndef CONV_H
#define CONV_H

#include <vector>

// Declarations
void conv1d(std::vector<std::vector<int>>* input_ptr, int M, int N, int k, int stride, std::vector<int>* output_ptr);

void conv2d(std::vector<std::vector<int>>* input_ptr, int H, int W, int kh, int kw, int stride, std::vector<std::vector<int>>* output_ptr);

#endif