class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        ret, mn = 0, float('inf')
        for price in prices:
            if price < mn:
                mn = price
            if price - mn > ret:
                ret = price-mn
        return ret
