import torch

def my_entr(input):
    """
    Computes the element-wise entropy of the input tensor.

    Args:
        input (torch.Tensor): The input tensor.
    """
    n=input.numel()
    output = torch.zeros_like(input)    # Initialize output tensor with the same shape as input
    for i in range(n):
        if input[i] == 0:   # If the input is zero, the entropy is defined to be zero
            output[i] = 0
        elif input[i] < 0:  # If the input is negative, the entropy is undefined, so we can set it to negative infinity
            output[i] = -float('inf')
        else:               # For positive input, compute the entropy using the formula: -p * log(p)
            output[i] = -input[i].mul(torch.log(input[i]))
    return output