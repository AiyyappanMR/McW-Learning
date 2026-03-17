import torch

def my_logaddexp(a,b):
    if a.shape != b.shape:
        if a.numel() == 1:
            a = a.expand_as(b)
        elif b.numel() == 1:
            b = b.expand_as(a)
        else:
            raise ValueError("Size mismatch and neither is a scalar.")
    return torch.log(torch.exp(a)+torch.exp(b))
