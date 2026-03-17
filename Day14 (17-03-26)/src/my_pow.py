import torch 

def my_pow(base, exp):
    """
    Computes the element-wise power of a tensor: base^exp.
    
    This function handles broadcasting when either `base` or `exp` is a scalar. 
    If both tensors have different shapes and neither is a scalar, it raises a ValueError.
    
    Args:
        base (torch.Tensor): First input tensor.
        exp (torch.Tensor): Second input tensor.
    """

    # Check for shape compatibility and handle broadcasting for scalars
    if base.shape != exp.shape:
        if base.numel() == 1:
            base = base.expand_as(exp)
        elif exp.numel() == 1:
            exp = exp.expand_as(base)
        else:
            # Raise error if tensors are different shapes and neither can be broadcasted as a scalar
            raise ValueError("Size mismatch and neither is a scalar.")

    # Computes base^exp using a loop to multiply base by itself exp times
    result=torch.ones_like(base)
    for i in range(len(base)):
        for _ in range(int(exp[i].item())):
            result[i].mul_(base[i])
    return result
    
        