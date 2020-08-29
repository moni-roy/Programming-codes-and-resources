class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        list = sorted((val[0], i) for i, val in enumerate(intervals))
        ans = []
        for invl in intervals:
            r = bisect.bisect_left(list, (invl[1],))
            ans.append(list[r][1] if r < len(list) else -1)
        return ans
