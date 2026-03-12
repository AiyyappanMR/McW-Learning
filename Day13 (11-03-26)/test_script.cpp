#include <gtest/gtest.h>
#include <torch/torch.h>
#include "conv.hpp" 

using namespace std;

// GTests 
// converting vector<vector<int>> to torch::Tensor
torch::Tensor to_tensor(const vector<vector<int>>& vec) {
    int rows = vec.size();
    int cols = vec[0].size();
    auto options = torch::TensorOptions().dtype(torch::kInt32);
    torch::Tensor t = torch::empty({rows, cols}, options);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            t[i][j] = vec[i][j];
        }
    }
    return t;
}

// TEST 1: Conv1D - Input 2x6, Kernel 3, Stride 1
TEST(Conv1DTest, Kernel3Stride1) {
    int M = 2, N = 6, k = 3, stride = 1;
    vector<vector<int>> input(M, vector<int>(N, 1));
    vector<int> custom_output;
    conv1d(&input, M, N, k, stride, &custom_output);

    torch::Tensor t_input = to_tensor(input).view({1, M, N});
    torch::Tensor t_weight = torch::empty({1, M, k}, torch::kInt32);
    for(int i=0; i<M; i++) for(int j=0; j<k; j++) t_weight[0][i][j] = i+1;

    torch::Tensor t_output = torch::conv1d(t_input, t_weight, {}, stride);
    
    for(int i=0; i<custom_output.size(); i++) {
        EXPECT_EQ(custom_output[i], t_output[0][0][i].item<int>());
    }
}

// TEST 2: Conv1D - Input 1x4, Kernel 2, Stride 2
TEST(Conv1DTest, Kernel2Stride2) {
    int M = 1, N = 4, k = 2, stride = 2;
    vector<vector<int>> input = {{1, 2, 3, 4}};
    vector<int> custom_output;
    conv1d(&input, M, N, k, stride, &custom_output);
    
    torch::Tensor t_input = to_tensor(input).view({1, M, N});
    torch::Tensor t_weight = torch::empty({1, M, k}, torch::kInt32);
    for(int i=0; i<M; i++) for(int j=0; j<k; j++) t_weight[0][i][j] = i+1;

    torch::Tensor t_output = torch::conv1d(t_input, t_weight, {}, stride);
    
    for(int i=0; i<custom_output.size(); i++) {
        EXPECT_EQ(custom_output[i], t_output[0][0][i].item<int>());
    }
}

// TEST 3: Conv2D - 4x4 Input, 2x2 Kernel, Stride 2
TEST(Conv2DTest, Matrix4x4Stride2) {
    int H = 4, W = 4, kh = 2, kw = 2, stride = 2;
    vector<vector<int>> input(H, vector<int>(W, 1));
    vector<vector<int>> custom_output;
    conv2d(&input, H, W, kh, kw, stride, &custom_output);

    torch::Tensor t_input = to_tensor(input).view({1, 1, H, W});
    torch::Tensor t_weight = torch::empty({1, 1, kh, kw}, torch::kInt32);
    for(int i=0; i<kh; i++) for(int j=0; j<kw; j++) t_weight[0][0][i][j] = i + j;

    torch::Tensor t_output = torch::conv2d(t_input, t_weight, {}, stride);

    for(int i=0; i<custom_output.size(); i++) {
        for(int j=0; j<custom_output[0].size(); j++) {
            EXPECT_EQ(custom_output[i][j], t_output[0][0][i][j].item<int>());
        }
    }
}

// TEST 4: Conv2D - 5x5 Input, 3x3 Kernel, Stride 1
TEST(Conv2DTest, Matrix5x5Stride1) {
    int H = 5, W = 5, kh = 3, kw = 3, stride = 1;
    vector<vector<int>> input(H, vector<int>(W, 2));
    vector<vector<int>> custom_output;
    conv2d(&input, H, W, kh, kw, stride, &custom_output);

    torch::Tensor t_input = to_tensor(input).view({1, 1, H, W});
    torch::Tensor t_weight = torch::empty({1, 1, kh, kw}, torch::kInt32);
    for(int i=0; i<kh; i++) for(int j=0; j<kw; j++) t_weight[0][0][i][j] = i + j;

    torch::Tensor t_output = torch::conv2d(t_input, t_weight, {}, stride);

    for(int i=0; i<custom_output.size(); i++) {
        for(int j=0; j<custom_output[0].size(); j++) {
            EXPECT_EQ(custom_output[i][j], t_output[0][0][i][j].item<int>());
        }
    }
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}