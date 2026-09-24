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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right)
            return head;
        
        ListNode* dummy = new ListNode();
        ListNode* prev = new ListNode();

        dummy->next = head;
        prev = dummy;

        int nodesToReverse = right - left;

        while(--left > 0)
            prev = prev->next;

        ListNode* curr = prev->next;

        while(nodesToReverse-- > 0) {
            ListNode* temp = curr->next;
            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }

        return dummy->next;
    }
};