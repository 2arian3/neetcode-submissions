class Node {
public:
    int key;
    int value;
    Node* next;
    Node* prev;
    
    Node(int key, int value) {
        this->key = key;
        this->value = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
class LRUCache {
private:
    unordered_map<int, Node*> lru;
    Node* left;
    Node* right;
    int capacity;

    void insert(Node* node) {
        left->next->prev = node;
        node->next = left->next;
        left->next = node;
        node->prev = left;
    }

    void erase(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        left = new Node(-1, -1);
        right = new Node(-1, -1);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if (lru.contains(key)) {
            Node* node = lru[key];
            erase(node);
            insert(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (lru.contains(key)) {
            Node* node = lru[key];
            erase(node);
            node->value = value;
            insert(node);
            return;
        } 
        Node* node = new Node(key, value);
        if (lru.size() == capacity){
            Node* temp = right->prev;
            erase(temp);
            lru.erase(temp->key);
            delete temp;
        }
        insert(node);
        lru[key] = node;
        return;
    }
};
