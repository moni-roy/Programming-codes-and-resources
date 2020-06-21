class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        n, m = len(dungeon), len(dungeon[0])
        dp = [[float('inf')]*(m+1) for i in range(n+1)]
        dp[n][m-1], dp[n-1][m] = 1, 1

        for i in range(n-1, -1, -1):
            for j in range(m-1, -1, -1):
                dp[i][j] = min(dp[i][j+1], dp[i+1][j]) - dungeon[i][j]
                dp[i][j] = 1 if dp[i][j] <= 0 else dp[i][j]

        return dp[0][0]
