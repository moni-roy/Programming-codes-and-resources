class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        last, ans = float('-inf'), 0
        for s, e in sorted(intervals, key=lambda x: x[1]):
            if s >= last:
                last = e
            else:
                ans += 1
        return ans
