class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        dp = [0]*(amount+1)
        dp[0] = 1
        for coin in coins:
            for cur in range(1, amount+1):
                if cur >= coin:
                    dp[cur] += dp[cur-coin]
        return dp[amount]
