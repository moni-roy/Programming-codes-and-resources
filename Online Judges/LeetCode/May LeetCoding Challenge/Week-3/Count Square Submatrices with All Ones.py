class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        if matrix is None or len(matrix) == 0:
            return 0

        row = len(matrix)
        col = len(matrix[0])

        ans = 0
        for r in range(row):
            for c in range(col):
                if matrix[r][c] == 1:
                    if r == 0 or c == 0:
                        ans += 1
                    else:
                        square = min(matrix[r-1][c-1],
                                     matrix[r][c-1], matrix[r-1][c]) + 1
                        ans += square
                        matrix[r][c] = square
        return ans
