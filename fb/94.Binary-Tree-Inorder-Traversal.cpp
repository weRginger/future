// Morris Traversal
// Time O(n)
// Space O(1), better than using a stack
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* curr = root;
        TreeNode* pre;
        while(curr) {
            if(!curr->left) {
                res.push_back(curr->val);
                curr = curr->right; // move to next right node
            } else { // has a left subtree
                pre = curr->left;
                while(pre->right) { // find rightmost
                    pre = pre->right;
                }
                pre->right = curr; // put cur after the pre node
                TreeNode* temp = curr; // store cur node
                curr = curr->left; // move cur to the top of the new tree
                temp->left = nullptr; // original cur left be null, avoid infinite loops
            }
        }
        return res;
    }
};
