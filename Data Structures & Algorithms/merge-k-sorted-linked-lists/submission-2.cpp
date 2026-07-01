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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
        
        auto comp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> mHeap(comp);

        for (ListNode* l: lists) {
            if (l)
                mHeap.push(l);
        }

        ListNode* res = new ListNode(0);
        ListNode* curr = res;

        while(!mHeap.empty()) {
            ListNode* top = mHeap.top();
            mHeap.pop();

            curr->next = top;
            curr = top;
            if (top->next)
                mHeap.push(top->next);
        }

        return res->next;
    }
};
