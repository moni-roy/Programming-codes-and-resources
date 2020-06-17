impl Solution {
    pub fn solve(board: &mut Vec<Vec<char>>) {
        if board.is_empty() {
            return
        }
        let (R, C) = (board.len(), board[0].len());
        
        for r in 0..R{
            Solution::dfs(r, 0, R, C, board);
            Solution::dfs(r, C-1, R, C, board);
        }
        
        for c in 0..C{
            Solution::dfs(0, c, R, C, board);
            Solution::dfs(R-1, c, R, C, board);
        }
        
        for r in 0..R{
            for c in 0..C{
                if board[r][c] == 'M'{
                    board[r][c] = 'O'
                }
                else {
                    board[r][c] = 'X'
                }
            }
        }
        
    }
    
    fn dfs(r: usize, c: usize, R: usize, C: usize, board: &mut Vec<Vec<char>>) {
        if board[r][c] == 'O'{
            board[r][c]='M';
            
            if r>0 { Solution::dfs(r-1, c, R, C, board) }
            if r<R-1 { Solution::dfs(r+1, c, R, C, board) }
            if c>0 { Solution::dfs(r, c-1, R, C, board) }
            if c<C-1 { Solution::dfs(r, c+1, R, C, board) }
        }
    }
    
}