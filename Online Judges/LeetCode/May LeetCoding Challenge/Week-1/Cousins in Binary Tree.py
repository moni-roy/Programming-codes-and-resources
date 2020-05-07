# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        def recursion(node: TreeNode, parent: TreeNode, depth: int):
            if not node or len(found) == 2:
                return
            if node.val == x or node.val == y:
                found.append((parent, depth))
            recursion(node.left, node, depth + 1)
            recursion(node.right, node, depth + 1)
        found = []
        recursion(root, None, 0)
        return (found[0][0] != found[1][0]) and (found[0][1] == found[1][1])
