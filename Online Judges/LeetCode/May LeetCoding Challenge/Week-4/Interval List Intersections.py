class Solution:
    def intervalIntersection(self, A: List[List[int]], B: List[List[int]]) -> List[List[int]]:
        lenA = len(A)
        lenB = len(B)
        ans = []
        i, j = 0, 0
        while i < lenA and j < lenB:
            low = max(A[i][0], B[j][0])
            high = min(A[i][1], B[j][1])

            if low <= high:
                ans.append((low, high))
            if(A[i][1] < B[j][1]):
                i += 1
            else:
                j += 1
        return ans
