impl Solution {
    pub fn get_permutation(n: i32, k: i32) -> String {
        let mut numStr: Vec<char> = (0..n as u8).map(|a|(b'1' + a) as char).collect();
        let mut k:i32 = k-1;
        let mut factN:i32 = (1..n).product();
        
        let mut Ans: String = String::with_capacity(n as usize);
        for i in 0..n-1{
            let id:usize = (k/factN) as usize;
            k %= factN;
            Ans.push(numStr[id]);
            numStr.remove(id);
            factN = factN / (n - 1 - i)
        }
        Ans.push(numStr[0]);
        return Ans;
    }
}