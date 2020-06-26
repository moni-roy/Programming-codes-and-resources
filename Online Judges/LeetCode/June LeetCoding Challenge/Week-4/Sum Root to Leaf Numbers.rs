// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn sum_numbers(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        Solution::sumNum(root, 0)
    }
    
    fn sumNum(root: Option<Rc<RefCell<TreeNode>>>, sum:i32)->i32 {
        if let Some(r)=root{
            if r.borrow().left.is_none() && r.borrow().right.is_none() {
                return sum*10 + r.borrow().val;
            }
            return Solution::sumNum(r.borrow().left.clone(), sum*10 + r.borrow().val) + Solution::sumNum(r.borrow().right.clone(), sum*10 + r.borrow().val);
        }
        else {
            return 0;
        }
    }
}