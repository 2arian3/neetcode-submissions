class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = []

        def backtrack(curr: List[int], currSum: int, i: int):
            if currSum == target:
                res.append(curr.copy())
                return

            if currSum > target or i >= len(nums):
                return

            curr.append(nums[i])
            backtrack(curr, currSum + nums[i], i)
            curr.pop()
            backtrack(curr, currSum, i + 1)
                
        
        backtrack([], 0, 0)
        return res