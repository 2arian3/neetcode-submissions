/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* start = head;
        ListNode* tail = start;

        int nodeCounter = 0;
        stack<ListNode*> nodesToReverse = {};

        while (head != nullptr) {
            nodesToReverse.push(head);
            nodeCounter++;
            head = head->next;

            if (head != nullptr && nodeCounter == k - 1) {
                ListNode* nextHead = head->next;

                if (tail == start) {
                    start = head;
                } else {
                    tail->next = head;
                }

                while (!nodesToReverse.empty()) {
                    ListNode* tmp = nodesToReverse.top();
                    nodesToReverse.pop();
                    head->next = tmp;
                    head = tmp;
                }
                tail = head;
                head->next = nextHead;

                head = nextHead;

                nodeCounter = 0;
            }
        }


        return start;
    }
};
