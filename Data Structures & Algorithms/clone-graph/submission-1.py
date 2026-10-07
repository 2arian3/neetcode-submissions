"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None

        valToNew = {}
        valToNew[node.val] = Node(node.val)
        q = deque([node])

        while q:
            curr = q.popleft()
            for nei in curr.neighbors:
                if nei.val not in valToNew:
                    valToNew[nei.val] = Node(nei.val)
                    q.append(nei)
                
                valToNew[curr.val].neighbors.append(valToNew[nei.val])


        return valToNew[node.val]
