// Time O(n)
// Space O(H)
// author ziqi. note: the termination condition actually makes the function to search for p and q existence within root
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) {
            return root;
        }
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        if(!l) return r;
        if(!r) return l;
        return root;
    }
};

// Note this solution can deal if the target node(s) are NOT in the tree
class Solution2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* one, TreeNode* two) {
        TreeNode* ans = lca(root, one, two);
        if (ans == one) {
            return find(one, two) == true ? ans : NULL;
        } else if (ans == two) {
            return find(two, one) == true ? ans : NULL;
        }
        return ans;
    }

private:
    TreeNode* lca(TreeNode* root, TreeNode* one, TreeNode* two) {
        if (root == NULL || root == one || root == two) {
            return root;
        }
        TreeNode* left = lca(root->left, one, two);
        TreeNode* right = lca(root->right, one, two);
        if (left != NULL && right != NULL) {
            return root;
        }
        return left == NULL ? right : left;
    }

    // check if node is under root
    bool find(TreeNode* root, TreeNode* node) {
        if (root == NULL) {
            return false;
        }
        if (root == node) {
            return true;
        }
        return find(root->left, node) || find(root->right, node);
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

