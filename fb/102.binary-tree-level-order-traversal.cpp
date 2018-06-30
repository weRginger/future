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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int s = q.size();
            vector<int> cur;
            for(int i = 0; i < s; i++) {
                TreeNode* n = q.front();
                q.pop();
                cur.push_back(n->val);
                if(n->left) {
                    q.push(n->left);
                }
                if(n->right) {
                    q.push(n->right);
                }
            }
            ans.push_back(cur);
        }
        return ans;
    }
};
