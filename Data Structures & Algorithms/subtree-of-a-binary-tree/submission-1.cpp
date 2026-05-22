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
    string getTraverseString(TreeNode* node) {
        if (!node) {
            return "#,";
        }
        
        return to_string(node->val) + "," + getTraverseString(node->left) + getTraverseString(node->right);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string rootStr = getTraverseString(root);
        string subStr = getTraverseString(subRoot);

        return rootStr.find(subStr) != string::npos;
    }
};
