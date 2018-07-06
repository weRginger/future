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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> st;
        bool found=false;
        if(!root)
            return NULL;
        while(!st.empty() || root) {
            if(root) {
                while(root) {
                    st.push(root);
                    root=root->left;
                }
            }
            else {
                root=st.top();
                st.pop();
                if(found)
                    return root;
                if(root == p)
                    found=true;
                root=root->right;
            }
        }
        return NULL;
    }
};