class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        if len(nums) <= 1:
            return 0
        prod = 1
        left, ret = 0, 0

        for right, num in enumerate(nums):
            prod *= num
            while prod >= k and left <= right:
                prod /= nums[left]
                left += 1
            ret += right - left + 1
        return ret
