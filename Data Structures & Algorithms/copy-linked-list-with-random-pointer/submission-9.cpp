/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> nodeMap = {};
        Node* newHead = new Node(-1000);
        Node* ptr = newHead;

        Node* temp = head;
        while (temp != nullptr) {
            ptr->next = new Node(temp->val);
            nodeMap[temp] = ptr->next;
            temp = temp->next;
            ptr = ptr->next;
        }

        ptr = newHead->next;
        while (head != nullptr) {
            ptr->random = head->random != nullptr ? nodeMap[head->random] : nullptr;
            head = head->next;
            ptr = ptr->next;
        }

        return newHead->next;
    }
};
