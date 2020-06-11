impl Solution {
    pub fn sort_colors(nums: &mut Vec<i32>) {
        if nums.len() <= 1 {
            return;
        }
        
        let mut i = 0;
        let mut j = 0;
        let mut k = nums.len() - 1;
        
        while j <= k && k > 0 {
            if nums[j] == 0 {
                nums.swap(i, j);
                i += 1;
                j += 1;
            } else if nums[j] == 1 {
                j += 1;
            } else {
                nums.swap(j, k);
                k -= 1;
            }
        }
    }
}