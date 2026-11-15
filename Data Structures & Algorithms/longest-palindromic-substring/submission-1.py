class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        dp = [[False] * n for _ in range(n)] 

        start, length = 0, 0

        dp[n - 1][n - 1] = True

        for i in range(n - 1, -1, -1):
            for j in range(i, n):
                if s[i] == s[j] and (j - i <= 2 or dp[i+1][j-1]):
                    dp[i][j] = True
                    
                    if j - i + 1 > length:
                        length = j - i + 1
                        start = i

        return s[start : start+length]
