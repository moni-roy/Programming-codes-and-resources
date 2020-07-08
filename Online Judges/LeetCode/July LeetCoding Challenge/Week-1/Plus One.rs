impl Solution {
    pub fn plus_one(mut digits: Vec<i32>) -> Vec<i32> {
        for digit in digits.iter_mut().rev() {
            *digit += 1;
            if *digit == 10 {
                *digit = 0;
            }
            else {
                return digits;
            }
        }
        digits.insert(0,1);
        return digits;
    }
}