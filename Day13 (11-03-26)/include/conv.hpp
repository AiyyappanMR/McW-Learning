#ifndef CONV_H
#define CONV_H

#include <vector>

using namespace std;

// Declarations
void conv1d(vector<vector<int>>* input_ptr, int num_channels, int input_length, int kernel_size,
            int stride,vector<int>* output_ptr);

void conv2d(vector<vector<int>>* input_ptr, int input_height, int input_width, int kernel_height,
            int kernel_width, int stride, vector<vector<int>>* output_ptr);

#endif