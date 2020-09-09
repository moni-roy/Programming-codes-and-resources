class Solution:
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        if t < 0:
            return False
        n = len(nums)
        d = {}
        w = t + 1
        for i in range(n):
            m = nums[i] // w
            # print(m)
            if m in d:
                return True
            if m - 1 in d and abs(nums[i] - d[m - 1]) < w:
                return True
            if m + 1 in d and abs(nums[i] - d[m + 1]) < w:
                return True
            d[m] = nums[i]
            if i >= k:
                del d[nums[i - k] // w]
        return False
