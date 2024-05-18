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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        helper(root, ans);
        return ans;
    }
    int helper(TreeNode* root, vector<vector<int>>& ans) {
        if(!root) return -1;
        int h = max(helper(root->left, ans), helper(root->right, ans)) + 1;
        while(ans.size() < h + 1) {
            ans.push_back(vector<int>());
        }
        ans[h].push_back(root->val);
        return h;
    }
};
