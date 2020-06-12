use rand::{self, Rng};

struct RandomizedSet {
    nums: Vec<i32>
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl RandomizedSet {

    /** Initialize your data structure here. */
    fn new() -> Self {
        RandomizedSet {
            nums: vec![]
        }
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    fn insert(&mut self, val: i32) -> bool {
        if self.nums.contains(&val) {
            return false;
        }
        else {
            self.nums.push(val);
            return true;
        }
        
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    fn remove(&mut self, val: i32) -> bool {
        if self.nums.contains(&val) {
            let index = self.nums.iter().position(|&r| r == val).unwrap();
            self.nums.remove(index);
            return true;
        }
        else {
            return false;
        }
    }
    
    /** Get a random element from the set. */
    fn get_random(&mut self) -> i32 {
        self.nums[rand::thread_rng().gen_range(0, self.nums.len())]
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * let obj = RandomizedSet::new();
 * let ret_1: bool = obj.insert(val);
 * let ret_2: bool = obj.remove(val);
 * let ret_3: i32 = obj.get_random();
 */