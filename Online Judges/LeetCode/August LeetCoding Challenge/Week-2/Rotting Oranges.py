class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        n, m, fresh, queue = len(grid), len(grid[0]), 0, deque()

        for i, j in product(range(n), range(m)):
            if grid[i][j] == 1:
                fresh += 1
            if grid[i][j] == 2:
                queue.append((i, j))

        dir = [[1, 0], [-1, 0], [0, 1], [0, -1]]

        rt = 0

        while queue:
            rt += 1
            for _ in range(len(queue)):
                u, v = queue.popleft()

                for x, y in dir:
                    if 0 <= u + x < n and 0 <= v + y < m and grid[u+x][v+y] == 1:
                        fresh -= 1
                        grid[u+x][v+y] = 2
                        queue.append((u+x, v+y))

        return -1 if fresh != 0 else max(rt-1, 0)
