use std::cmp;
impl Solution {
    pub fn num_squares(n: i32) -> i32 {
        let n = n as usize;
        let mut dp = vec![1009; n+1];
        dp[0] = 0;
        for i in 1..n+1 {
            for j in 1..i+1 {
                if j*j<=i {
                    dp[i] = cmp::min(dp[i], dp[i-j*j] +1);
                }
            }
        }
        dp[n]
    }
}