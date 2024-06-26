// Time O(n)
// Space O(width)
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        queue<TreeNode*>  q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size(), mx = INT_MIN;
            for(int i=0;i<n;i++) {
                TreeNode *top = q.front();
                q.pop();
                mx = max(mx,top->val);
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
            ans.push_back(mx);
        }return ans;
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
