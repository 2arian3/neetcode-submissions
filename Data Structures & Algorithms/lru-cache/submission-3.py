class Node:

    def __init__(self, key: int = 0, value: int = 0):
        self.key = key
        self.value = value
        self.nxt = None
        self.prv = None


class LinkedList:

    def __init__(self):
        self.left = Node()
        self.right = Node()
        self.left.nxt = self.right
        self.right.prv = self.left


    def insert(self, node: Node):
        node.nxt = self.left.nxt
        self.left.nxt.prv = node
        node.prv = self.left
        self.left.nxt = node

    
    def remove(self, node: Node):
        node.prv.nxt = node.nxt
        node.nxt.prv = node.prv
        del node


class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.nodeList = LinkedList()
        self.keyToNode = {}
        

    def get(self, key: int) -> int:
        if key not in self.keyToNode:
            return -1

        node = self.keyToNode[key]
        self.nodeList.remove(node)
        self.nodeList.insert(node)

        return node.value
        

    def put(self, key: int, value: int) -> None:
        if key in self.keyToNode:
            node = self.keyToNode[key]
            node.value = value
            self.nodeList.remove(node)
            self.nodeList.insert(node)

        else:
            if self.capacity == len(self.keyToNode):
                nodeToRemove = self.nodeList.right.prv
                self.keyToNode.pop(nodeToRemove.key)
                self.nodeList.remove(nodeToRemove)

            node = Node(key, value)
            self.keyToNode[key] = node
            self.nodeList.insert(node)
