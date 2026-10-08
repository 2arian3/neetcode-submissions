# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        maxPath = float('-inf')
        
        def dfs(node: Optional[TreeNode]) -> int:
            nonlocal maxPath

            if not node:
                return 0

            leftMax = max(dfs(node.left), 0)
            rightMax = max(dfs(node.right), 0)

            maxPath = max(maxPath, node.val + leftMax + rightMax)

            return max(leftMax, rightMax) + node.val


        dfs(root)
        return maxPath


        