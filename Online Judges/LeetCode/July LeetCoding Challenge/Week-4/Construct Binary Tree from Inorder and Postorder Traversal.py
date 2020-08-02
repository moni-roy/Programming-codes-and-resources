# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        map_in = {}
        for id, val in enumerate(inorder):
            map_in[val] = id

        def recur(low, high):
            if low > high:
                return None
            node = TreeNode(postorder.pop())
            md = map_in[node.val]
            node.right = recur(md + 1, high)
            node.left = recur(low, md-1)
            return node
        return recur(0, len(inorder)-1)
