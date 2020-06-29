impl Solution {
    pub fn unique_paths(m: i32, n: i32) -> i32 {
        let n = n as usize;
        let m = m as usize;
        let mut v = vec![1; n];
        
        for i in 1..m{
            for j in 1..n {
                v[j] += v[j-1];
            }
        }
        v[n-1]
    }
}