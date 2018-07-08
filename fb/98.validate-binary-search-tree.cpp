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
    bool isValid(TreeNode* root, TreeNode* l=NULL, TreeNode* r=NULL) {
        if(!root) return true;
        if (l != NULL and root->val <= l->val) return false;
        if (r != NULL and root->val >= r->val) return false;
        return (isValid(root->left,l,root))&&(isValid(root->right,root,r));
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root);
    }
};

class Solution2 {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        vector<int> v;
        inorderTraversal(root, v);
        for(int i = 1; i < v.size(); i++) {
            if(v[i-1] >= v[i]) return false;
        }
        return true;
    }
    void inorderTraversal(TreeNode* root, vector<int>& v) {
        if(!root) return;
        inorderTraversal(root->left, v);
        v.push_back(root->val);
        inorderTraversal(root->right, v);
    }
};
