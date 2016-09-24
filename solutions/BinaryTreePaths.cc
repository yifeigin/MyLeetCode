/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void BTHelper(TreeNode* root, vector<string> &data, string val) {
        if (!root->left && !root->right) {
            data.push_back(val);
            return;
        }
        if (root->left) BTHelper(root->left, data, val+"->"+to_string(root->left->val));
        if (root->right) BTHelper(root->right, data, val+"->"+to_string(root->right->val));
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> data;
        if (!root) return data;
        BTHelper(root, data, to_string(root->val));
        return data;
    }
};