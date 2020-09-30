class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        total = 0
        x, y = 0, 0
        for row in range(rows):
            for col in range(cols):
                if grid[row][col] >= 0:
                    total += 1
                if grid[row][col] == 1:
                    x, y = row, col
        ret = 0

        def back(rem, u, v):
            nonlocal ret
            if grid[u][v] == 2 and rem == 1:
                ret += 1
                return
            tm = grid[u][v]
            grid[u][v] = -2

            for dx, dy in [(0, 1), (1, 0), (-1, 0), (0, -1)]:
                xx = u + dx
                yy = v + dy

                if xx >= 0 and xx < rows and yy >= 0 and yy < cols and grid[xx][yy] >= 0:
                    back(rem-1, xx, yy)
            grid[u][v] = tm

        back(total, x, y)
        return ret
