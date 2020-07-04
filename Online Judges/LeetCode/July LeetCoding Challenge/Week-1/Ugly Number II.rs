use std::cmp::min;
impl Solution {
    pub fn nth_ugly_number(n: i32) -> i32 {
        let n = n as usize;
        let mut v = vec![1;n+1];
        let mut i = 0 as usize;
        let mut k = 0 as usize;
        let mut j = 0 as usize;
        for l in 0..n{
            let t = min(v[i]*2, min(v[j]*3, v[k]*5));
            if t == v[i]*2{
                i = i+1;
            }
            if t == v[j]*3{
                j = j+1;
            }
            if t == v[k]*5{
                k = k+1
            }
            v[l+1] = t;
        }
        return v[n-1];
    }
}