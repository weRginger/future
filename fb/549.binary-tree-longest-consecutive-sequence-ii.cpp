// Time O(n)
// Space O(H)
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
class Solution {
private:
    int maxval = 0;

    // return {inr, dcr}
    // inr means the longest increasing sequence from current node
    // dcr means the longest decreasing sequence from current node
    vector<int> helper(TreeNode* root) {
        if(!root) return {0, 0};
        
        int inr = 1, dcr = 1; // init with itself
        if (root->left) {
            auto left = helper(root->left);
            if (root->val == root->left->val + 1) {
                dcr = left[1] + 1;
            } else if (root->val == root->left->val - 1) {
                inr = left[0] + 1;
            }
        }
        
        if (root->right) {
            auto right = helper(root->right);
            if (root->val == root->right->val + 1) {
                dcr = max(dcr, right[1] + 1);
            } else if (root->val == root->right->val - 1) {
                inr = max(inr, right[0] + 1);
            }
        }
        
        maxval = max(maxval, dcr + inr - 1); // itself is included twice
        return {inr, dcr};
    }
public:
    int longestConsecutive(TreeNode* root) {
        helper(root);
        return maxval;
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
