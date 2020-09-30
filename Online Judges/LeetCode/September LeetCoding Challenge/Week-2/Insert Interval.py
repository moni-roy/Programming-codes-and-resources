class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        left,  right = [], []
        s = newInterval[0]
        e = newInterval[1]
        for it in intervals:
            if it[1] < s:
                left.append(it)
            elif it[0] > e:
                right.append(it)
            else:
                s = min(s, it[0])
                e = max(e, it[1])

        return left + [[s, e]] + right
