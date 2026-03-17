import torch

def my_logaddexp(a, b):
    """
    Computes the element-wise log-addition of exponentials: log(exp(a) + exp(b)).
    
    This function handles broadcasting when either `a` or `b` is a scalar. 
    If both tensors have different shapes and neither is a scalar, it raises a ValueError.
    
    Args:
        a (torch.Tensor): First input tensor.
        b (torch.Tensor): Second input tensor.
    """
    
    # Check for shape compatibility and handle broadcasting for scalars
    if a.shape != b.shape:
        if a.numel() == 1:
            a = a.expand_as(b)
        elif b.numel() == 1:
            b = b.expand_as(a)
        else:
            # Raise error if tensors are different shapes and neither can be broadcasted as a scalar
            raise ValueError(f"Size mismatch and neither is a scalar.")

    # Computes log(exp(a) + exp(b)) 
    return torch.log(torch.add(torch.exp(a), torch.exp(b)))