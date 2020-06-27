class Solution:
    def numSquares(self, n: int) -> int:
        dp = [1e9]*(n+1)
        dp[0] = 0
        for i in range(1, n+1):
            for j in range(1, i+1):
                if(j*j > i):
                    break
                dp[i] = min(dp[i], dp[i-j*j] + 1)
        return dp[n]
