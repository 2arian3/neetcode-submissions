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
private:
    void add(ListNode*& head, ListNode*& nodeToAdd) {
        ListNode* temp = nodeToAdd->next;
        head->next = nodeToAdd;
        head = nodeToAdd;
        nodeToAdd = temp;

        return;
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* curr = head;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                add(curr, list1);
            } else {
                add(curr, list2);
            }
        }

        while (list1)
            add(curr, list1);
        while (list2)
            add(curr, list2);

        return head->next;
    }
};
