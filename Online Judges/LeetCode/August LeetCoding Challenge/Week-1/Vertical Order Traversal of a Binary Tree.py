# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def verticalTraversal(self, root: TreeNode) -> List[List[int]]:
        ans = collections.defaultdict(list)
        queue = collections.deque([(root, 0)])

        while queue:
            tmp = collections.defaultdict(list)
            for _ in range(len(queue)):
                node, dis = queue.popleft()
                tmp[dis] += [node.val]
                if node.left:
                    queue.append((node.left, dis-1))
                if node.right:
                    queue.append((node.right, dis+1))

            for i in tmp:
                ans[i] += sorted(tmp[i])

        return [ans[i] for i in sorted(ans)]
