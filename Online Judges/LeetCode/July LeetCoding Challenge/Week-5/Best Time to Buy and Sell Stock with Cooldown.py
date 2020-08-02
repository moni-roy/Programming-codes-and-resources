class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) <= 1:
            return 0
        A, B, C = 0, -prices[0], 0

        for i in range(1, len(prices)):
            T = A
            A = max(A, C)
            C = B + prices[i]
            B = max(B, T - prices[i])
        return max(A, C)
