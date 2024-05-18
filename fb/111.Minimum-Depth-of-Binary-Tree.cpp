// Time O(n)
// Space O(logn) on average, O(n) on worst
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        int l = INT_MAX, r = INT_MAX;
        if(root->left)
            l = minDepth(root->left);
        if(root->right)
            r = minDepth(root->right);
        return min(l, r) + 1;
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
