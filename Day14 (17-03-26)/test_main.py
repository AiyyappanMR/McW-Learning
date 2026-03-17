import torch
import pytest
from main import my_logaddexp

@pytest.mark.parametrize("input_a, input_b", [
    (torch.tensor([-10.0, 20.0, -3.0]), torch.tensor([-1.0, -2.0, -3.0])),
    (torch.tensor([50.0, 5.0]), torch.tensor([-1.0, -2.0])),
    (torch.tensor([1.0]), torch.tensor([1.0])),
])
def test_my_logaddexp(input_a, input_b):
    expected = torch.logaddexp(input_a, input_b)
    result = my_logaddexp(input_a, input_b)
    torch.testing.assert_close(result, expected)