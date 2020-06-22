impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        let mut first:i32 = 0;
        let mut second:i32 = 0;
        
        for num in nums{
            first = (first ^ num) & !second;
            second = (second ^ num) & !first;
        }
        first
    }
}