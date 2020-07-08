impl Solution {
    pub fn island_perimeter(grid: Vec<Vec<i32>>) -> i32 {
        let mut ans:i32 = 0;
        let mut neg:i32 = 0;
        let n  = grid.len() as usize;
        let m = grid[0].len() as usize;
        
        for i in 0..n{
            for j in 0..m{
                if grid[i][j] == 1 {
                    ans += 1;
                    if i < n-1 && grid[i+1][j] == 1 {
                        neg += 1;
                    }
                    if j<m-1 && grid[i][j+1] == 1 {
                        neg += 1;
                    }
                }
            }
        }
        return ans*4 - neg*2;
    }
}