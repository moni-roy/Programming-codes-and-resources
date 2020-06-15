# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        def search(root1: TreeNode, val: int) -> TreeNode:
            # print(root1)
            if root1 is None:
                return None
            if root1.val == val:
                return root1
            elif root1.val < val:
                return search(root1.right, val)
            else:
                return search(root1.left, val)
        return search(root, val)
