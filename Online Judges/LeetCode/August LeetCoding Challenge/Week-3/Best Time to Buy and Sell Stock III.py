class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 0:
            return 0
        dp = [[0 for x in range(len(prices))] for y in range(3)]
        for k in range(1, 3):
            mn = prices[0]
            for i in range(1, len(prices)):
                mn = min(mn, prices[i] - dp[k-1][i-1])
                dp[k][i] = max(dp[k][i-1], prices[i] - mn)
        return dp[2][len(prices)-1]
