class Solution:
    def maxUncrossedLines(self, A: List[int], B: List[int]) -> int:
        lenA, lenB = len(A), len(B)
        dp = defaultdict(int)

        for i in range(lenA):
            for j in range(lenB):
                dp[i, j] = max(dp[i-1, j-1] + (A[i] == B[j]),
                               dp[i-1, j], dp[i, j-1])
        return dp[lenA-1, lenB-1]
