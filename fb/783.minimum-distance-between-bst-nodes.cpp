// Time O(n)
// Space O(h)
class Solution {
public:
    int minDistance = INT_MAX;
    // Initially, it will be null.
    TreeNode* predecessor;
        
    void inorderTraversal(TreeNode* root) {
        if (!root) return;
        
        inorderTraversal(root->left);
        // Find the difference with the predecessor value if it is there.
        if (predecessor) {
            minDistance = min(minDistance, root->val - predecessor->val);
        }
        predecessor = root;
        inorderTraversal(root->right);
    }
    
    int minDiffInBST(TreeNode* root) {
        inorderTraversal(root);
        return minDistance;
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
