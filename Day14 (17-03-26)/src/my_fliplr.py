import torch

def my_fliplr(input):
    """
    Flips a 2D tensor left-to-right.
    """
    # 1. Validation for exactly 2D
    if input.dim() != 2:
        raise ValueError("This function only supports 2D tensors.")
    
    # 2. Get the number of columns
    num_cols = input.size(1)
    
    # 3. Create the reverse index for the columns
    rev_idx = torch.arange(num_cols - 1, -1, -1).long()
    
    # 4. Apply indexing to flip the tensor
    return input[:, rev_idx]