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
    unordered_map<TreeNode*, int> canRobM;
    unordered_map<TreeNode*, int> cannotRobM;

public:
    int rob(TreeNode* root) {
        return dfs(root, true);
    }

    int dfs(TreeNode* node, bool canRob) {
        if (!node)
            return 0;
        
        if (canRob && canRobM.contains(node))
            return canRobM[node];

        if (!canRob && cannotRobM.contains(node))
            return cannotRobM[node];

        int result;

        if (canRob) {
            result = max(
                node->val + dfs(node->left, false) + dfs(node->right, false),
                dfs(node->left, true) + dfs(node->right, true)
            );

            canRobM[node] = result;
        } else {
            result = dfs(node->left, true) + dfs(node->right, true);
            
            cannotRobM[node] = result;
        }

        return result;
    }
};