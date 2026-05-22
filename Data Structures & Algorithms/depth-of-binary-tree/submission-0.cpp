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
    int depth(TreeNode* node, int d) {
        if (node == nullptr) {
            return 0;
        }

        return 1 + max(
            depth(node->right, d + 1),
            depth(node->left, d + 1)
        );
    }
public:
    int maxDepth(TreeNode* root) {
        return depth(root, 0);
    }
};
