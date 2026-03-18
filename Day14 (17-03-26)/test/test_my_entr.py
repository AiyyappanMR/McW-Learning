import torch
import pytest
from src import my_entr

# Test cases for my_entr function
@pytest.mark.parametrize("input_tensor", [
    # 1. all positives
    torch.tensor([0.5, 0.25, 0.25]),
    # 2. all Zeros
    torch.tensor([0.0, 0.0, 0.0]),
    # 3. all Negatives
    torch.tensor([-1.0, -0.5, -0.25]),
    # 4.  positive, zero, and negative 
    torch.tensor([0.5, 0.0, -0.5]),
])
# Test the my_entr function against PyTorch's built-in torch.special.entr for correctness.
def test_my_entr(input_tensor):
    expected = torch.special.entr(input_tensor)
    result = my_entr(input_tensor)
    torch.testing.assert_close(result.float(), expected.float())