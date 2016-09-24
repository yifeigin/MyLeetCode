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
    void insert(TreeNode* root, vector<int> & temp) {
        if (!root) return;
        if (root->left) insert(root->left, temp);
        temp.push_back(root->val);
        if (root->right) insert(root->right, temp);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        insert(root, res);
        return res;
    }
};