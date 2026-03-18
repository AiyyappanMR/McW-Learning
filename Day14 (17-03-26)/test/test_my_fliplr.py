import torch
import pytest
from src import my_fliplr

# Test cases for my_fliplr function
@pytest.mark.parametrize("input_tensor", [
    # 1. Standard 2D tensor (Normal matrix)
    (torch.tensor([[1, 2, 3], [4, 5, 6]])),
    # 2. 1D tensor (Incompatible shape: should trigger our error handling)
    (torch.tensor([1, 2, 3, 4])),
    # 3. Square matrix of size 3x3
    (torch.eye(3)),
    # 4. 3D tensor 2x2x2 
    (torch.tensor([[[1, 2], [3, 4]], [[5, 6], [7, 8]]])),
])

# Test the my_fliplr function against PyTorch's built-in torch.fliplr for correctness.
def test_my_fliplr(input_tensor):
    # If the input dimension is less than 2, we expect a ValueError.
    if input_tensor.dim() < 2:
        with pytest.raises((ValueError, RuntimeError)):
            torch.fliplr(input_tensor)  # it raises RuntimeError
            my_fliplr(input_tensor)     # it raises ValueError
            
    # For compatible shapes (at least 2D), we compare with Pytorch result.
    else:
        expected = torch.fliplr(input_tensor)
        result = my_fliplr(input_tensor)
        torch.testing.assert_close(result, expected)