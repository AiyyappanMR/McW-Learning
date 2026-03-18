import torch

def my_fliplr(input):
    """
    Flips the input tensor along the 1st dimension. 
    The input dimensions should be greater than 2.
    """
    # 1. Validation for at least 2D
    if input.dim() < 2:
        raise ValueError("This function supports tensors with at least 2 dimensions.")
    
    # 2. Get the number of columns
    num_cols = input.size(1)
    
    # 3. Create the reverse index for the columns
    rev_idx = torch.arange(num_cols - 1, -1, -1)
    
    # uses index_select usually used to select specific indices along a dimension, 
    # but here we used it to reverse the order of 1st dimension.
    return torch.index_select(input, 1, rev_idx)