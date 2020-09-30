class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        vs = [0]*(len(nums)+1)

        for num in nums:
            if num > 0 and num <= len(nums):
                vs[num] = 1
        # print(vs)
        for i in range(1, len(nums)+1):
            if vs[i] == 0:
                return i
        return len(nums) + 1
