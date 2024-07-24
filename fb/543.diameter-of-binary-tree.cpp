// Time O(N)
// Space O(N)
class Solution {
private:
    int diameter = INT_MIN;

    int helper(TreeNode* root) {
        if(!root) return 0;
        int l = helper(root->left);
        int r = helper(root->right);

        // update the diameter if left_path plus right_path is larger
        // NOTE: since it is post-order traversal, no need to add 1 to l or r 
        diameter = max(l + r, diameter);

        // return the longest one between left_path and right_path;
        // remember to add 1 for the path connecting the node and its parent
        return max(l, r) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        return diameter;
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
