/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    int lcaComparison(TreeNode* lca, TreeNode* p, TreeNode* q) {
        if (lca->val < p->val && lca->val < q->val)
            return 1;
        else if (lca->val > p->val && lca->val > q->val)
            return -1;
        return 0;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca = root;

        while (true) {
            int whatToDo = lcaComparison(lca, p, q);
            if (!whatToDo)
                break;
            lca = whatToDo == 1 ? lca->right : lca->left;
        }

        return lca;
    }
};
