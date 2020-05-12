class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        ret = 0
        for num in nums:
            ret  = ret ^ num
        return ret