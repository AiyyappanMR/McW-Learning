import torch
import pytest
from src import my_pow

# Test cases for my_pow function
@pytest.mark.parametrize("base, exp", [
    # 1. Standard matching tensors (Positive integers)
    (torch.tensor([2.0, 3.0, 4.0]), torch.tensor([2, 3, 2])),
    # 2. Incompatible shapes (should trigger our error handling)
    (torch.tensor([1.0, 2.0, 3.0]), torch.tensor([1.0, 2.0])),
    # 3. Scalar base, tensor exponent 
    (torch.tensor([2.0]), torch.tensor([1, 2, 3])),
    # 4. Tensor base, scalar exponent 
    (torch.tensor([1.0, 2.0, 3.0]), torch.tensor([2])),
    # 5. base 1 and exp 0
    (torch.tensor([1.0]), torch.tensor([0])),
])

# Test the my_pow function against PyTorch's built-in torch.pow for correctness.
def test_my_pow(base, exp):
    # If the shapes are incompatible and neither is a scalar, we expect a ValueError.
    if base.shape != exp.shape and base.numel() != 1 and exp.numel() != 1:
        with pytest.raises((ValueError, RuntimeError)):
            my_pow(base, exp)   # it raises ValueError
            torch.pow(base, exp)  # it raises RuntimeError
            
    # For compatible shapes (including scalar broadcasting), we compare with Pytorch result.
    else:
        expected = torch.pow(base, exp)
        result = my_pow(base, exp)
        torch.testing.assert_close(result.float(), expected)