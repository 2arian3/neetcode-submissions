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
    unordered_map<int, ListNode*> nodeMap;

public:
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;

        int i = 0;
        ListNode* temp = head;

        while (temp) {
            nodeMap[i++] = temp;
            temp = temp->next;
        }

        int j = 0;
        i--;

        temp = nullptr;

        while (j < i) {
            if (temp)
                temp->next = nodeMap[j];
            temp = nodeMap[j];

            temp->next = nodeMap[i];
            temp = temp->next;

            j++;
            i--;
        }

        if (j == i) {
            temp->next = nodeMap[j];
            temp = temp->next;
        }

        temp->next = nullptr;
    }
};
