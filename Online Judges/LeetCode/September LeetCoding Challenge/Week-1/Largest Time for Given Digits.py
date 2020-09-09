class Solution:
    def largestTimeFromDigits(self, A: List[int]) -> str:
        maxtime = -1
        for h, i, j, k in itertools.permutations(A):
            hour = h*10 + i
            minute = j*10 + k
            if hour < 24 and minute < 60:
                maxtime = max(maxtime, hour * 60 + minute)

        if maxtime == -1:
            return ""
        else:
            return "{:02d}:{:02d}".format(maxtime // 60, maxtime % 60)
