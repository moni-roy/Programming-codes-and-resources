class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        N = len(days)
        durations = [1, 7, 30]
        @lru_cache(None)
        def dp(i):
            if i >= N:
                return 0
            ret = float('inf')
            j = i
            for c, d in zip(costs, durations):
                while j < N and days[j] < days[i] + d:
                    j += 1
                ret = min(ret, dp(j) + c)
            return ret
        return dp(0)
