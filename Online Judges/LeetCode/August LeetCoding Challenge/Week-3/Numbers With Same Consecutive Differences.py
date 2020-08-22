class Solution:
    def numsSameConsecDiff(self, N: int, K: int) -> List[int]:
        if N == 1:
            return [i for i in range(10)]
        ans = []

        def dfs(N, num):
            if N == 0:
                return ans.append(num)
            last = num % 10
            if (last + K) < 10:
                dfs(N-1, num*10 + last + K)
            if (last - K) >= 0:
                dfs(N-1, num*10 + last - K)
        for i in range(1, 10):
            dfs(N-1, i)
        return list(set(ans))
