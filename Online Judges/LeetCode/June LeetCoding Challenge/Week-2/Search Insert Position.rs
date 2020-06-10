use std::cmp::Ordering;

impl Solution {
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        let (mut low, mut high)=(0i32, nums.len() as i32 -1);
        
        while low<=high {
            let mid = (low + high)/2 as i32;
            
            match nums[mid as usize].cmp(&target) {
                Ordering::Equal => { return mid; }
                Ordering::Greater => { high = mid -1; }
                Ordering::Less => { low = mid +1; }
            }
        }
        return low;
    }
}