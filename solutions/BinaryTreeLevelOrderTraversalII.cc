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
    int Treeheight(TreeNode* root) {
        if (!root) return 0;
        return max(Treeheight(root->left), Treeheight(root->right))+1;
    }
    void InsertNode(TreeNode* root, vector<vector<int>> & result, int height) {
        if (!root) return;
        result[height].push_back(root->val);
        InsertNode(root->left, result, height - 1);
        InsertNode(root->right, result, height - 1);
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
       int height = Treeheight(root);
       vector<vector<int>> result(height, vector<int>{});
       InsertNode(root, result, height-1);
       return result;
       
    }
};