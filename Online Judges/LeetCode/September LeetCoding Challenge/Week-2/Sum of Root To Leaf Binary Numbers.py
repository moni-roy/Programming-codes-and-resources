# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def sumRootToLeaf(self, root: TreeNode) -> int:
        def cal(root, sm):
            # if not root:///////////////////////////?
            sm = sm*2 + root.val
            if not root.left and not root.right:
                return sm
            l = 0
            if root.left:
                l = cal(root.left, sm)
            r = 0
            if root.right:
                r = cal(root.right, sm)
            return l + r
        return cal(root, 0)
