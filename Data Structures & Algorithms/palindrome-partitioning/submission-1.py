class Solution:
    def partition(self, s: str) -> List[List[str]]:
        res = []
        curr = []

        def backtrack(curr: List[str], i: int):
            if i >= len(s):
                res.append(curr.copy())
                return

            for j in range(i, len(s)):
                if self._is_palindrome(s[i:j+1]):
                    curr.append(s[i:j+1])
                    backtrack(curr, j + 1)
                    curr.pop()

        backtrack(curr, 0)
        return res


    def _is_palindrome(self, s: str):
        l = 0
        r = len(s) - 1

        while l < r:
            if s[l] != s[r]:
                return False
            
            l += 1
            r -= 1

        return True