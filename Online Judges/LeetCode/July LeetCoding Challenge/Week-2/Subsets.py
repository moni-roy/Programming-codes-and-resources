class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = [[]]
        for num in nums:
            ans += [ex + [num] for ex in ans]
        return ans
