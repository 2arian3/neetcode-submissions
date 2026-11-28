from functools import reduce
from operator import xor

class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        total = 0

        def _backtrack(i: int, subset: list[int]):
            if i == len(nums):
                nonlocal total
                total += reduce(xor, subset, 0)
                return

            subset.append(nums[i])
            _backtrack(i+1, subset)
            subset.pop()

            _backtrack(i+1, subset)

        _backtrack(0, [])

        return total