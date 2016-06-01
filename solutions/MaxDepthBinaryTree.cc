// Yifei Wang
// LeetCode Question 104

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // First One:
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root==NULL) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

// Second One:
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root==NULL) return 0;
        int rightdepth = maxDepth(root->right) + 1;
        int leftdepth = maxDepth(root->left) + 1;
        if (rightdepth>leftdepth) return rightdepth;
        return leftdepth;
    }
};

