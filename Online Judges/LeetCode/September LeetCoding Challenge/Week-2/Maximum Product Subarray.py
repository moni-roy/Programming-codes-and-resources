class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        mn, mx, res = 1, 1, -math.inf
        for num in nums:
            n = mn * num
            m = mx * num

            mn = min(n, m, num)
            mx = max(n, m, num)

            res = max(res, mx, mn)
        return res
