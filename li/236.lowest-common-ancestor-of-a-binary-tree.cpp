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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        if(l && r) return root;
        if(l) return l;
        return r;
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

