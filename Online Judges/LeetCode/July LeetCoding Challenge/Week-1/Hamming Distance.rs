impl Solution {
    pub fn hamming_distance(x: i32, y: i32) -> i32 {
        let xy = x ^ y;
        return xy.count_ones() as i32;
    }
}