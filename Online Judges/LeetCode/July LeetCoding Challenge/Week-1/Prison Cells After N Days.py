class Solution:
    def prisonAfterNDays(self, cells: List[int], N: int) -> List[int]:
        T = int(max(N-1, 0)/14)*14
        N -= T
        for i in range(N):
            cells = [0] + [cells[k-1]^cells[k+1]^1 for k in range(1, 7)] + [0]
        return cells
