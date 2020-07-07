// Time O(n)
// Space O(1)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pVal = p->val;
        int qVal = q->val;
        TreeNode* node = root;
        while(node) {
            int parentVal = node->val;
            if(pVal > parentVal && qVal > parentVal) {
                node = node->right;
            } else if (pVal < parentVal && qVal < parentVal) {
                node = node->left;
            } else {
                return node;
            }
        }
        return nullptr;
    }
};

// Time O(n)
// Space O(n)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;
        if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        else if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        return root;
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
