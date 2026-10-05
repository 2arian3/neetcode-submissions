class Solution:
    def numSquares(self, n: int) -> int:
        squares = [i ** 2 for i in range(1, math.ceil(math.sqrt(n)) + 1)]
        dp = [n] * (n + 1)
        dp[0] = 0

        for i in range(1, n + 1):
            for sq in squares:
                if i - sq < 0:
                    break
                dp[i] = min(dp[i], dp[i - sq] + 1)

        return dp[n]