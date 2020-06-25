impl Solution {
    pub fn find_duplicate(nums: Vec<i32>) -> i32 {
        let mut tortoise:i32 = nums[0];
        let mut hare:i32 = nums[0];
        
        loop {
            tortoise = nums[tortoise as usize];
            hare = nums[nums[hare as usize] as usize];
            if hare == tortoise {
                break;
            }
        }
        tortoise = nums[0];
        loop {
            if tortoise != hare {
                tortoise = nums[tortoise as usize];
                hare = nums[hare as usize];
            }
            else {
                return hare;
            }
        }       
    }
}