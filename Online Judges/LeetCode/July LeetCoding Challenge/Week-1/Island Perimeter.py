class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        ans, neg = 0, 0

        for i in range(n):
            for j in range(m):
                if grid[i][j]:
                    ans += 1
                    if i < n-1 and grid[i+1][j]:
                        neg += 1
                    if j < m-1 and grid[i][j+1]:
                        neg += 1
        return ans*4 - neg*2
