# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        self.ans = 0
        self.sum(root, 0)
        return self.ans

    def sum(self, root: TreeNode, total: int):
        if root is None:
            return
        if root.left is None and root.right is None:
            self.ans += (total*10 + root.val)
            return
        if root.left:
            self.sum(root.left, total*10 + root.val)
        if root.right:
            self.sum(root.right, total*10 + root.val)
