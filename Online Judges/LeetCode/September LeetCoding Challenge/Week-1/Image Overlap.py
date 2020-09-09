class Solution:
    def largestOverlap(self, A: List[List[int]], B: List[List[int]]) -> int:
        n = len(A)

        def countOne(x, y, A, B):
            ret = 0

            for ax, bx in enumerate(range(x, n)):
                for ay, by in enumerate(range(y, n)):
                    if A[ax][ay] == 1 and B[bx][by] == 1:
                        ret += 1
            return ret

        ans = 0

        for x in range(n):
            for y in range(n):
                ans = max(ans, countOne(x, y, A, B))
                ans = max(ans, countOne(x, y, B, A))
        return ans
