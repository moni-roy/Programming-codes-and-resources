class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = Counter(nums)
        ans = [key for key, i in count.most_common(k)]
        return ans
