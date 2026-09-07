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
    vector<vector<int>> res;
    unordered_set<int> createdDepth;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, 0);

        return res;
    }

    void dfs(TreeNode* node, int depth) {
        if (!node)
            return;
        
        if (!createdDepth.contains(depth)) {
            createdDepth.insert(depth);
            res.push_back({});
        }
        
        res[depth].push_back(node->val);

        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }
};
