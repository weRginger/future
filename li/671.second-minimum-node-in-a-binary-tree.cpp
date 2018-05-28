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
    int findSecondMinimumValue(TreeNode* root) {
        vector<int> v;
        helper(root, v);
        if(v.empty())
            return -1;
        int minimal = INT_MAX;
        for(auto i : v)
            minimal = min(minimal, i);
        return minimal;
    }
private:
    void helper(TreeNode* root, vector<int>& v) {
        if(!root || !root->left || !root->right)
            return;
        if(root->left->val == root->val)
            helper(root->left, v);
        else {
            v.push_back(root->left->val);
            return;
        }
        if(root->right->val == root->val)
            helper(root->right, v);
        else {
            v.push_back(root->right->val);
            return;
        }
    }
};