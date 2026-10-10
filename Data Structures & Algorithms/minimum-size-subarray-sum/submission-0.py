class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        l, r = 0, 0
        minLen = float('inf')

        currSum = 0
        while r < len(nums):
            currSum += nums[r]

            if currSum >= target:
                while l <= r and currSum - nums[l] >= target:
                    currSum -= nums[l]
                    l += 1
                minLen = min(minLen, r - l + 1)

            r += 1

        if minLen == float('inf'):
            return 0

        return minLen