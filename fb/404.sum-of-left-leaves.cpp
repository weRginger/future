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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root || (!root->left && !root->right)) return 0;
        int ans = 0;
        helper(root, ans, true);
        return ans;
    }

private:
    void helper(TreeNode* root, int& ans, bool isLeft) {
        if(!root) return;
        if(!root->left && !root->right && isLeft) {
            ans += root->val;
            return;
        }
        helper(root->left, ans, true);
        helper(root->right, ans, false);
    }
};