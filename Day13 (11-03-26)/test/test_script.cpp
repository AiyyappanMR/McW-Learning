#include <gtest/gtest.h>
#include <torch/torch.h>
#include "conv.hpp"

using namespace std;

// Convert vector<vector<int>> to torch::Tensor
torch::Tensor to_tensor(const vector<vector<int>>& vec) {
    int rows = vec.size();
    int cols = vec[0].size();
    auto options = torch::TensorOptions().dtype(torch::kInt32);
    torch::Tensor t = torch::empty({rows, cols}, options);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            t[i][j] = vec[i][j];
    return t;
}

// Build conv1d weight tensor — mirrors kernel formula in conv.cpp
torch::Tensor build_conv1d_weight(int num_channels, int kernel_size) {
    torch::Tensor t_weight = torch::empty({1, num_channels, kernel_size}, torch::kInt32);
    for (int channel = 0; channel < num_channels; channel++)
        for (int k = 0; k < kernel_size; k++)
            t_weight[0][channel][k] = channel + 1;
    return t_weight;
}

// Build conv2d weight tensor — mirrors kernel formula in conv.cpp
torch::Tensor build_conv2d_weight(int kernel_height, int kernel_width) {
    torch::Tensor t_weight = torch::empty({1, 1, kernel_height, kernel_width}, torch::kInt32);
    for (int row = 0; row < kernel_height; row++)
        for (int col = 0; col < kernel_width; col++)
            t_weight[0][0][row][col] = row + col;
    return t_weight;
}

// Validate conv1d custom output against PyTorch output
void validate_conv1d(const vector<int>& custom_output,
                     const torch::Tensor& t_output) {
    ASSERT_EQ(custom_output.size(), (size_t)t_output.size(2));
    for (int i = 0; i < (int)custom_output.size(); i++)
        EXPECT_EQ(custom_output[i], t_output[0][0][i].item<int>());
}

// Validate conv2d custom output against PyTorch output
void validate_conv2d(const vector<vector<int>>& custom_output,
                     const torch::Tensor& t_output) {
    ASSERT_EQ(custom_output.size(), (size_t)t_output.size(2));
    for (int i = 0; i < (int)custom_output.size(); i++) {
        ASSERT_EQ(custom_output[0].size(), (size_t)t_output.size(3));
        for (int j = 0; j < (int)custom_output[0].size(); j++)
            EXPECT_EQ(custom_output[i][j], t_output[0][0][i][j].item<int>());
    }
}

// CONV1D PARAMETERIZED TEST

struct Conv1DParams {int num_channels; int input_length; int kernel_size; int stride;
    vector<vector<int>> input;};

class Conv1DTest : public testing::TestWithParam<Conv1DParams> {};

TEST_P(Conv1DTest, ValidateAgainstPyTorch) {
    Conv1DParams p = GetParam();

    // Run custom conv1d
    vector<int> custom_output;
    conv1d(&p.input, p.num_channels, p.input_length,
           p.kernel_size, p.stride, &custom_output);

    // Build PyTorch tensors
    torch::Tensor t_input  = to_tensor(p.input).view({1, p.num_channels, p.input_length});
    torch::Tensor t_weight = build_conv1d_weight(p.num_channels, p.kernel_size);
    torch::Tensor t_output = torch::conv1d(t_input, t_weight, {}, p.stride);

    // Validate
    validate_conv1d(custom_output, t_output);
}

INSTANTIATE_TEST_SUITE_P(
    Conv1DTests,
    Conv1DTest,
    testing::Values(
        // Kernel size 3, stride 1, 2 channels, all ones input
        Conv1DParams{
            2, 6, 3, 1,
            vector<vector<int>>(2, vector<int>(6, 1))
        },
        // Kernel size 2, stride 2, 1 channel, sequential input
        Conv1DParams{
            1, 4, 2, 2,
            {{1, 2, 3, 4}}
        }
    )
);

// CONV2D PARAMETERIZED TEST

struct Conv2DParams {int input_height; int input_width; int kernel_height; int kernel_width;
    int stride; vector<vector<int>> input;};

class Conv2DTest : public testing::TestWithParam<Conv2DParams> {};

TEST_P(Conv2DTest, ValidateAgainstPyTorch) {
    Conv2DParams p = GetParam();

    // Run custom conv2d
    vector<vector<int>> custom_output;
    conv2d(&p.input, p.input_height, p.input_width, p.kernel_height, p.kernel_width, p.stride, 
        &custom_output);

    // Build PyTorch tensors
    torch::Tensor t_input  = to_tensor(p.input).view({1, 1, p.input_height, p.input_width});
    torch::Tensor t_weight = build_conv2d_weight(p.kernel_height, p.kernel_width);
    torch::Tensor t_output = torch::conv2d(t_input, t_weight, {}, p.stride);

    // Validate
    validate_conv2d(custom_output, t_output);
}

INSTANTIATE_TEST_SUITE_P(Conv2DTests, Conv2DTest,
    testing::Values(
        // 4x4 input, 2x2 kernel, stride 2, all ones input
        Conv2DParams{4, 4, 2, 2, 2,vector<vector<int>>(4, vector<int>(4, 1))},
        // 5x5 input, 3x3 kernel, stride 1, all twos input
        Conv2DParams{5, 5, 3, 3, 1,vector<vector<int>>(5, vector<int>(5, 2))}
    )
);

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}