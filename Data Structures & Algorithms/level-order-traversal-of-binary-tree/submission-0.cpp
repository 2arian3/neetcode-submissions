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
    unordered_map<int, vector<int>> depthMap;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, 0);

        vector<vector<int>> res;

        for (auto const m: depthMap)
            res.push_back(m.second);
        
        return vector<vector<int>>(res.rbegin(), res.rend());
    }
    void dfs(TreeNode* node, int depth) {
        if (!node)
            return;
        depthMap[depth].push_back(node->val);
        dfs(node->left, depth+1);
        dfs(node->right, depth+1);
        return;
    }
};
