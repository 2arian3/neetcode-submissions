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
    int res = INT_MIN;
public:
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return res;
    }
    void dfs(TreeNode* node, int& k) {
        if (!node) {
            return;
        }

        dfs(node->left, k);
        
        k--;
        if (k == 0) {
            res = node->val;
            return;
        }

        dfs(node->right, k);
    }
};
