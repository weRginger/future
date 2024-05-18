/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <climits>

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root) return vector<int>();
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int m = INT_MIN;
            for(int i = 0, s = q.size(); i < s; i++) {
                TreeNode* n = q.front();
                q.pop();
                m = max(m, n->val);
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            }
            ans.push_back(m);
        }
        return ans;
    }
};

