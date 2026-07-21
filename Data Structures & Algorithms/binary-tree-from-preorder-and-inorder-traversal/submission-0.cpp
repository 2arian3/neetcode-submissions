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
    unordered_map<int, int> inorderMap;
    int preI = 0;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++)
            inorderMap[inorder[i]] = i;
        
        return dfs(0, inorder.size() - 1, preorder);
    }

    TreeNode* dfs(int l, int r, vector<int>& preorder) {
        if (l > r) {
            return nullptr;
        }
        int rootVal = preorder[preI];
        preI++;

        TreeNode* root = new TreeNode(rootVal);
        root->left = dfs(l, inorderMap[rootVal] - 1, preorder);
        root->right = dfs(inorderMap[rootVal] + 1, r, preorder);
        return root;
    }
};
