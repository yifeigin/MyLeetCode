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
private:
    bool CheckBoth(TreeNode* Left, TreeNode* Right) {
        if (!Left && !Right) return true;
        if (!Left || !Right) return false;
        if (Left->val != Right->val) return false;
        return CheckBoth(Left->left, Right->right) && CheckBoth(Left->right, Right->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return CheckBoth(root->left, root->right);
    }
};