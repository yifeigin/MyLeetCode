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
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int leftBalance = 0;
        int rightBalance = 0;
        int diff = 0;
        if (!isBalanced(root->left) || !isBalanced(root->right)) return false;
        if (!root->left && !root->right) root->val = 1;
        if (root->left) leftBalance = root->left->val;
        if (root->right) rightBalance = root->right->val;
        if (leftBalance > rightBalance) {
            if (leftBalance - rightBalance>1) return false;
            root->val = leftBalance + 1;
            return true;
        }
        if (rightBalance - leftBalance>1) return false;
        root->val = rightBalance + 1;
        return true;
    }
};