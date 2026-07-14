class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache;

    Node* left;
    Node* right;

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node* node) {
        node->next = left->next;
        node->prev = left;

        left->next->prev = node;
        left->next = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;

        left = new Node(0, 0);
        right = new Node(0, 0);

        left->next = right;
        right->prev = left;
    }

    int get(int key) {
        if (!cache.count(key))
            return -1;

        Node* node = cache[key];

        remove(node);
        insert(node);

        return node->val;
    }

    void put(int key, int value) {
        if (cache.count(key)) {
            Node* node = cache[key];
            node->val = value;

            remove(node);
            insert(node);
            return;
        }

        if (cache.size() == capacity) {
            Node* lru = right->prev;

            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }

        Node* node = new Node(key, value);
        insert(node);
        cache[key] = node;
    }
};