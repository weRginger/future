// Time O(n)
// Space O(n)
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans = INT_MIN;
        helper(root, ans);
        return ans;
    }

private:
    int helper(TreeNode* root, int& ans) {
        if(!root) return -1;
        int l = root->left ? helper(root->left, ans) + 1 : 0;
        int r = root->right ? helper(root->right, ans) + 1 : 0;
        ans = max(ans, l + r);
        return max(l, r);
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
