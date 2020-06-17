class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if len(board) == 0:
            return
        q = deque()
        R = len(board)
        C = len(board[0])
        for r in range(R):
            q.append((r, 0))
            q.append((r, C-1))
        for c in range(C):
            q.append((0, c))
            q.append((R-1, c))

        while q:
            r, c = q.popleft()
            if 0 <= r < len(board) and 0 <= c < len(board[0]) and board[r][c] == "O":
                board[r][c] = "M"
                q.append((r+1, c))
                q.append((r-1, c))
                q.append((r, c-1))
                q.append((r, c+1))
        for r in range(R):
            for c in range(C):
                if board[r][c] == "M":
                    board[r][c] = "O"
                else:
                    board[r][c] = "X"
