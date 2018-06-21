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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s) return false;
        return sameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }

private:
    bool sameTree(TreeNode* t1, TreeNode* t2) {
        if(!t1 && !t2) {
            return true;
        }
        else if(!t1 || !t2) {
            return false;
        }
        else if(t1->val != t2->val) {
            return false;
        }
        return sameTree(t1->left, t2->left) && sameTree(t1->right, t2->right);
    }
};