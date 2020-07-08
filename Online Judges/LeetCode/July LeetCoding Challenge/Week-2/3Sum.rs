impl Solution {
    pub fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut ans = Vec::new();
        
        let n = nums.len() as usize;
        
        let mut nums = nums;
        nums.sort();
        
        for i in 0..n {
            if i==0 || (i>0 && nums[i-1] != nums[i]) {
                
                let mut low = i + 1;
                let mut high = nums.len() - 1;
                let extra =  - nums[i];
                
                while low < high {
                    if (nums[low] + nums[high]) == extra{
                        
                        let v = vec![nums[i], nums[low], nums[high]];
                        ans.push(v);
                    
                        while (low < high) && (nums[low] == nums[low+1]){
                            low += 1;
                        }
                        while ((high > low) && (nums[high] == nums[high - 1])){
                            high -= 1;
                        }
                    }
                    if extra > (nums[low] + nums[high]){
                        low +=1;
                    }
                    else{
                        high -= 1;
                    }
                }
            }
        }
        return ans;
    }
}