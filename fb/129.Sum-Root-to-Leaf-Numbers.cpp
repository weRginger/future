// Time O(n)
// Space O(H) -> could be reduced to O(1) if using Morris traversal. Go to LC for details.
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        helper(root, 0);
        return sum;
    }
private:
    int sum = 0;
    void helper(TreeNode* root, int pre) {
        if(!root)
            return;
        if(!root->left && !root->right) {
            sum += pre * 10 + root->val;
            return;
        }
        helper(root->left, pre * 10 + root->val);
        helper(root->right, pre * 10 + root->val);
    }
};

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
