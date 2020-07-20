// Time O(n)
// Space O(H)
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        longestPath(root);
        return maxval;
    }
private:
    int maxval = 0;
    
    pair<int, int> longestPath(TreeNode* root) {
        if(!root)
            return {0,0};
        int inr = 1, dcr = 1;
        if(root->left) {
            auto l = longestPath(root->left);
            if (root->val == root->left->val + 1)
                dcr = l.first + 1;
            else if (root->val == root->left->val - 1)
                inr = l.second + 1;
        }
        if(root->right) {
            auto r = longestPath(root->right);
            if (root->val == root->right->val + 1)
                dcr = max(dcr, r.first + 1);
            else if (root->val == root->right->val - 1)
                inr = max(inr, r.second + 1);
        }
        maxval = max(maxval, dcr + inr - 1);
        return {dcr, inr};
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
