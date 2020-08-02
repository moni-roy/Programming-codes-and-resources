# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        queue, result, temp, flag = [root], [], [], 1

        while queue:
            for _ in range(len(queue)):
                node = queue.pop(0)
                temp += [node.val]
                if node.left:
                    queue += [node.left]
                if node.right:
                    queue += [node.right]
            result.append(temp[::flag])
            temp = []
            flag *= -1
        return result
