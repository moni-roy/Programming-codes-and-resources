# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        if root is None:
            return 0

        def helper(root: TreeNode, flag):
            if root is None:
                return 0
            if root.left == None and root.right == None:
                if flag:
                    return root.val
            return helper(root.left, 1) + helper(root.right, 0)
        return helper(root, 0)
