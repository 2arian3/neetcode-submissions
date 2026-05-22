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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum = new ListNode(-1);
        ListNode* curr = sum;
        ListNode* extra;

        bool done = false;
        int toAdd = 0;
        int newVal = 0;
        while (!done) {
            newVal = (toAdd + l1->val + l2->val) % 10;
            toAdd = (toAdd + l1->val + l2->val) / 10;
            l1 = l1->next;
            l2 = l2->next;

            curr->next = new ListNode(newVal);
            curr = curr->next;

            if (l1 == nullptr || l2 == nullptr) {
                done = true;
                extra = l1 == nullptr ? l2 : l1;
            }
        }

        while (extra != nullptr || toAdd) {
            int extraVal = extra != nullptr ? extra->val : 0;
            newVal = (toAdd + extraVal) % 10;
            toAdd = (toAdd + extraVal) / 10;
            curr->next = new ListNode(newVal);
            curr = curr->next;
            if (extra != nullptr) {
                extra = extra->next;
            }
        }

        return sum->next;
    }
};
