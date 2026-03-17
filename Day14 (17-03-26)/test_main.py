import torch
import pytest
from main import my_logaddexp

# Test cases for my_logaddexp function
@pytest.mark.parametrize("input_a, input_b", [
    # 1. Standard matching tensors
    (torch.tensor([-10.0, 20.0, -3.0]), torch.tensor([-1.0, -2.0, -3.0])),
    # 2. Incompatible shapes (should trigger our error handling)
    (torch.tensor([50.0, 5.0,6.0]), torch.tensor([-1.0, -2.0])),
    # 3. One scalar and one tensor (should broadcast the scalar)
    (torch.tensor([1.0,0.0]), torch.tensor([0.0])),
])

# Test the my_logaddexp function against PyTorch's built-in torch.logaddexp for correctness.
def test_my_logaddexp(input_a, input_b):
    # If the shapes are incompatible and neither is a scalar, we expect a ValueError.
    if input_a.shape != input_b.shape and input_a.numel() != 1 and input_b.numel() != 1:
        with pytest.raises((ValueError, RuntimeError)):
            torch.logaddexp(input_a, input_b)  # it raises RuntimeError
            my_logaddexp(input_a, input_b)     # it raises ValueError
            
    # For compatible shapes (including scalar broadcasting), we compare with Pytorch result.
    else:
        expected = torch.logaddexp(input_a, input_b)
        result = my_logaddexp(input_a, input_b)
        torch.testing.assert_close(result, expected)