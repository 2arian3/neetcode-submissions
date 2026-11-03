# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        res = 0

        def dfs(node: TreeNode, maxSeen = float('-inf')):
            if not node:
                return

            if maxSeen <= node.val:
                nonlocal res
                res += 1

            dfs(node.right, max(maxSeen, node.val))
            dfs(node.left, max(maxSeen, node.val))

        dfs(root)

        return res