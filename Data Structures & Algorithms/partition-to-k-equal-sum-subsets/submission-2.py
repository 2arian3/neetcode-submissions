class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        if sum(nums) % k != 0:
            return False

        picked = [False for _ in range(len(nums))]
        target = sum(nums) / k

        nums.sort(reverse=True)

        def backtrack(i: int, k: int, subSum: int):
            if k == 0:
                return True

            if subSum == target:
                return backtrack(0, k - 1, 0)

            for j in range(i, len(nums)):
                if picked[j] or subSum + nums[j] > target:
                    continue

                picked[j] = True

                if backtrack(j + 1, k, subSum + nums[j]):
                    return True

                picked[j] = False

            return False

        
        return backtrack(0, k, 0)
        