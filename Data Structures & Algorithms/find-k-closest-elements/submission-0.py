class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        l, r = 0, len(arr) - 1

        while r - l + 1 > k:
            leftDiff = abs(arr[l] - x)
            rightDiff = abs(arr[r] - x)

            if leftDiff <= rightDiff:
                r -= 1
            else:
                l += 1

        return arr[l:r + 1]