#include <iostream>
#include <vector>
#include "conv.hpp"

using namespace std;

// Performs a 1D cross-correlation (convolution) over a multi-channel input.
void conv1d(vector<vector<int>>* input_ptr, int num_channels, int input_length, int kernel_size,
            int stride, vector<int>* output_ptr) {

    auto& input = *input_ptr;

    // Initialize kernels for each channel
    vector<vector<int>> kernel(num_channels, vector<int>(kernel_size));
    for (int channel = 0; channel < num_channels; channel++) {
        for (int k = 0; k < kernel_size; k++) {
            kernel[channel][k] = channel + 1;
        }
    }

    // Calculate output size
    int output_size = (input_length - kernel_size) / stride + 1;
    output_ptr->assign(output_size, 0);
    auto& output = *output_ptr;

    // 1D convolution operation
    int out_idx = 0;
    int offset = 0;  // horizontal window offset based on stride

    while (out_idx < output_size) {
        for (int channel = 0; channel < num_channels; channel++) {
            for (int k = 0; k < kernel_size; k++) {
                output[out_idx] += input[channel][k + offset] * kernel[channel][k];
            }
        }
        offset += stride;
        out_idx++;
    }
}

// Function to perform 2D convolution on a single-channel matrix
void conv2d(vector<vector<int>>* input_ptr, int input_height, int input_width, int kernel_height, int kernel_width, 
            int stride, vector<vector<int>>* output_ptr) {
    
    auto& input = *input_ptr;

    // Initializing the 2D kernel
    vector<vector<int>> kernel(kernel_height, vector<int>(kernel_width));
    for (int row = 0; row < kernel_height; row++) {
        for (int col = 0; col < kernel_width; col++) {
            kernel[row][col] = row + col; // kernel value = sum of row and col indices
        }
    }

    // Calculating output dimensions 
    int out_height = (input_height - kernel_height) / stride + 1;
    int out_width  = (input_width  - kernel_width)  / stride + 1;
    
    output_ptr->assign(out_height, vector<int>(out_width, 0));
    auto& output = *output_ptr;

    // Performing the convolution operation
    for (int i = 0; i < out_height; i++) {       // Kernel vertical slide 
        for (int j = 0; j < out_width; j++) {   // Kernel horizontal slide
            
            int sum = 0;
            // Kernel matrix row traversal
            for (int m = 0; m < kernel_height; m++) {
                // Kernel matrix column traversal
                for (int n = 0; n < kernel_width; n++) {
                    // Calculate input coordinates using stride
                    int row = i * stride + m;
                    int col = j * stride + n;
                    sum += input[row][col] * kernel[m][n];
                }
            }
            output[i][j] = sum;
        }
    }
}