use std::cmp::max;
impl Solution {
    pub fn prison_after_n_days(cells: Vec<i32>, n: i32) -> Vec<i32> {
        let mut N = n;
        let mut T:i32 = max(N-1, 0)/14;
        N = N - T*14;
        let N = N as usize;
        let mut v = cells;
        for i in 0..N{
            let mut v2 = vec![0;8];
            v2[0] = 0;
            v2[7] = 0;
            for j in 1..7{
                v2[j] = (v[j-1] == v[j+1]) as i32;
            }
            v = v2;
        }
        return v;
    }
}