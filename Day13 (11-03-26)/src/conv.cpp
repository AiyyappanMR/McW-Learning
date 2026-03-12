#include <iostream>
#include <vector>

using namespace std;

// Performs 1D convolution on a matrix with M channels and length N
void conv1d(vector<vector<int>>* input_ptr, int M, int N, int k, int stride, vector<int>* output_ptr){
    auto& input = *input_ptr;
    
    // Initialize kernels for each channel
    vector<vector<int>> kernel(M,vector<int>(k));
    for(int i=0;i<M;i++){
        for(int j=0;j<k;j++){
            kernel[i][j]=i+1; // Set kernel values equal to the channel index
        }
    }

    // Calculate output size using formula
    int output_size = (N - k) / stride + 1;
    output_ptr->assign(output_size, 0);
    auto& output = *output_ptr;

    // 1D convolution operation
    int out_idx = 0;   // Current position in the output vector
    int i = 0;         // Horizontal offset in the input based on stride   
    while (out_idx < output_size) {
        for(int j = 0; j < M; j++) {           
            for(int l = 0; l < k; l++) {
                // Sum products across all channels and kernel width
                output[out_idx] += input[j][l + i] * kernel[j][l]; 
            }
        }
        // Move window by stride and increment output index
        i += stride;   
        out_idx++;   
    }
}

// Function to perform 2D convolution on a single-channel matrix
void conv2d(vector<vector<int>>* input_ptr, int H, int W, int kh, int kw, int stride, vector<vector<int>>* output_ptr) {
    auto& input = *input_ptr;

    // Initializing the 2D kernel
    vector<vector<int>> kernel(kh, vector<int>(kw));
    for(int i = 0; i < kh; i++) {
        for(int j = 0; j < kw; j++) {
            kernel[i][j] = i + j; // eg. kernel with values = sum of i and j.
        }
    }

    // Calculating output dimensions 
    int out_h = (H - kh) / stride + 1;
    int out_w = (W - kw) / stride + 1;
    
    output_ptr->assign(out_h, vector<int>(out_w, 0));
    auto& output = *output_ptr;

    // Performing the convolution operation
    for (int i = 0; i < out_h; i++) {       // Kernel vertical slide 
        for (int j = 0; j < out_w; j++) {   // Kernel horizontal slide
            
            int sum = 0;
            // Kernel matrix row traversal
            for (int m = 0; m < kh; m++) {
                // Kernel matrix column traversal
                for (int n = 0; n < kw; n++) {
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