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
public:
    vector<int> rightNodes = {};

    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);

        return rightNodes;
    }
private:
    void dfs(TreeNode* node, int depth) {
        if (!node)
            return;
        
        if (rightNodes.size() == depth)
            rightNodes.push_back(node->val);
        
        dfs(node->right, depth+1);
        dfs(node->left, depth+1);
    }
};
