class Node:

    def __init__(self, key: int, val: int):
        self.key = key
        self.val = val
        self.prv = None
        self.nxt = None
        self.freq = 1


class LinkedList:

    def __init__(self):
        self.left = Node(-1, -1)
        self.right = Node(-1, -1)

        self.left.nxt = self.right
        self.right.prv = self.left

        self.length = 0

    
    def insert(self, node: Node):
        nxt = self.left.nxt
        nxt.prv = node
        node.nxt = nxt
        node.prv = self.left
        self.left.nxt = node

        self.length += 1


    def delete(self, node: Node):
        prv, nxt = node.prv, node.nxt
        prv.nxt = nxt
        nxt.prv = prv
        node.prv = None
        node.nxt = None
        
        self.length -= 1



class LFUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity

        self.nodeMap = {} # Each value is a Node object
        self.listMap = defaultdict(LinkedList)

        self.minFreq = 0


    def _update(self, node: Node):
        freq = node.freq
        self.listMap[freq].delete(node)

        if freq == self.minFreq and self.listMap[freq].length == 0:
            self.minFreq += 1

        node.freq += 1
        self.listMap[node.freq].insert(node)

       

    def get(self, key: int) -> int:
        if key not in self.nodeMap:
            return -1

        node = self.nodeMap[key]
        self._update(node)

        return node.val
        

    def put(self, key: int, value: int) -> None:
        if key in self.nodeMap:
            node = self.nodeMap[key]
            node.val = value
            self._update(node)
            return

        if len(self.nodeMap) == self.capacity:
            node = self.listMap[self.minFreq].right.prv
            self.nodeMap.pop(node.key)
            self.listMap[self.minFreq].delete(node)

        node = Node(key, value)
        self.nodeMap[key] = node
        self.minFreq = 1
        self.listMap[self.minFreq].insert(node)
        


# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)