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
    int res = 0;
public:
    int goodNodes(TreeNode* root) {
        dfs(root, -1000);
        return res;
    }
    void dfs(TreeNode* node, int max) {
        if (!node)
            return;
        if (max <= node->val) {
            res++;
            max = node->val;
        }
        dfs(node->left, max);
        dfs(node->right, max);
    }
};
