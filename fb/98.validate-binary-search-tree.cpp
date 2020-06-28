// Time O(n)
// Space O(n)
class Solution {
private:
    vector<int> vals;
    
    void inorderTraversal(TreeNode* root) {
        if(!root) return;
        inorderTraversal(root->left);
        vals.push_back(root->val);
        inorderTraversal(root->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        inorderTraversal(root);
        for(int i = 1; i < vals.size(); i++) {
            if(vals[i] <= vals[i-1])
                return false;
        }
        return true;
    }
};

// Time O(n)
// Space O(n)
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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
