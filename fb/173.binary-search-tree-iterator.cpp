// Time O(n)
// Space O(h) - h is tree height
class BSTIterator {
private:
    stack<TreeNode*> stk;
    
    void leftmostInorder(TreeNode* root) {
        // For a given node, add all the elements in the leftmost branch of the tree
        // under it to the stack.
        while(root) {
            stk.push(root);
            root = root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        leftmostInorder(root);
    }
    
    /** @return the next smallest number */
    int next() {
        assert(!stk.empty());
        TreeNode* node = stk.top();
        stk.pop();
        leftmostInorder(node->right);
        return node->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
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

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
