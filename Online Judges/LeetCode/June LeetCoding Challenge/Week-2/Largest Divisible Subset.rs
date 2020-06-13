impl Solution {
    pub fn largest_divisible_subset(mut nums: Vec<i32>) -> Vec<i32> {
        nums.sort();
        let n = nums.len();
        let mut dp = vec![1; n];
        let mut mx = 0;
        let mut num = 0;
        
        for i in 0..n{
            for j in 0..i{
                if nums[i]%nums[j] == 0{
                    if dp[i] < dp[j]+1{
                        dp[i] = dp[j] + 1;
                    }
                }
            }
            if mx < dp[i] {
                mx = dp[i];
                num = nums[i];
            }
        }
        // println!("{}", mx);
        let mut result = vec![];
        for i in (0..n).rev()
        {
            if dp[i] == mx && num%nums[i]==0 {
                result.push(nums[i]);
                mx-=1;
                num = nums[i];
            }
        }
        result
    }
}