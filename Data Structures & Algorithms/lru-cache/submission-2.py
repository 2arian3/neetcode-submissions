class Node:
    def __init__(self, key: int, val: int):
        self.key = key
        self.val = val
        self.next = self.prev = None

class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.kv = {}
        self.left, self.right = Node(-1, -1), Node(-1, -1)

        self.left.next = self.right
        self.right.prev = self.left


    def _insert(self, node: Node):
        temp = self.left.next

        self.left.next = node
        node.prev = self.left

        node.next = temp
        temp.prev = node

    
    def _remove(self, node: Node):
        node.prev.next = node.next
        node.next.prev = node.prev
        del node
        

    def get(self, key: int) -> int:
        if key in self.kv:
            self._remove(self.kv[key])
            self._insert(self.kv[key])
            return self.kv[key].val

        return -1
        

    def put(self, key: int, value: int) -> None:
        if key in self.kv:
            self._remove(self.kv[key])
        
        self.kv[key] = Node(key, value)
        self._insert(self.kv[key])

        if len(self.kv) > self.capacity:
            temp = self.right.prev
            self._remove(temp)
            del self.kv[temp.key]
