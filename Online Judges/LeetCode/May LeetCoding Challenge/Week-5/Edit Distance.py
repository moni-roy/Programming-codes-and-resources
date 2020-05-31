class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n, m = len(word1), len(word2)
        dp = [[0]*(m+1) for i in range(0, n+1)]
        for i in range(0, n+1):
            dp[i][0] = i
        for i in range(0, m+1):
            dp[0][i] = i

        for i in range(0, n):
            for j in range(0, m):
                dp[i+1][j+1] = min(dp[i][j] + (word1[i] !=
                                               word2[j]), dp[i][j+1] + 1, dp[i+1][j] + 1)
        return dp[n][m]
