// Time O(n)
// Space O(n)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool fromLeft = true;
        while(!q.empty()) {
            int s = q.size();
            vector<int> cur(s, 0);
            for(int i = 0; i < s; i++) {
                TreeNode* n = q.front();
                q.pop();
                if(fromLeft) {
                    cur[i] = n->val;
                }
                else {
                    cur[s - 1 - i] = n->val;
                }
                if(n->left) {
                    q.push(n->left);
                }
                if(n->right) {
                    q.push(n->right);
                }
            }
            ans.push_back(cur);
            if(fromLeft) {
                fromLeft = false;
            }
            else {
                fromLeft = true;
            }
        }
        return ans;
    }
};
