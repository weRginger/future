// Time O(n)
// Space O(n)
class Solution {
public:
    int preInd;
    unordered_map<int,int>mp;
    TreeNode * rec(vector<int>& pre, vector<int>& post,int l, int r){
        if(l == r)return new TreeNode(pre[preInd++]);
        if(l > r)return NULL;
        TreeNode * curr = new TreeNode(pre[preInd++]);
        int t = mp[pre[preInd]];
        curr->left = rec(pre,post,l,t);
        curr->right = rec(pre,post,t + 1,r-1);
        return curr;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        preInd = 0;
        for(int i = 0; i < post.size(); i++)mp[post[i]] = i;
        return rec(pre,post,0,post.size()-1);
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
