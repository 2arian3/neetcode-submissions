class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        maximums = []

        q = deque()
        r = 0

        while r < len(nums):
            while q and nums[q[-1]] < nums[r]:
                q.pop()
            
            q.append(r)
            
            if q[0] < r - k + 1:
                q.popleft()
            
            if r >= k - 1:
                maximums.append(nums[q[0]])
            
            r += 1

        return maximums