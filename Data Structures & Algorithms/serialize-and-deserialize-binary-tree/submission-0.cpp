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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "#,";
        }

        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string segment;
        vector<string> nodes;

        while (getline(ss, segment, ',')) {
            nodes.push_back(segment);
        }

        int i = 0;
        return dfsDeserialize(nodes, i);
    }

    TreeNode* dfsDeserialize(vector<string>& nodes, int& i) {
        if (nodes[i] == "#") {
            i++;
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(nodes[i++]));
        node->left = dfsDeserialize(nodes, i);
        node->right = dfsDeserialize(nodes, i);

        return node;
    }
};
