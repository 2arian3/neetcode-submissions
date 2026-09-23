class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* nodeToRemove = new ListNode();
        ListNode* dummy = new ListNode();

        nodeToRemove->next = head;
        dummy->next = head;

        ListNode* start = nodeToRemove;

        while (n-- >= 0 && dummy)
            dummy = dummy->next;
        
        while (dummy) {
            dummy = dummy->next;
            nodeToRemove = nodeToRemove->next;
        }

        nodeToRemove->next = nodeToRemove->next->next;
        
        return start->next;
    }
};