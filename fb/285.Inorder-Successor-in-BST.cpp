// Time O(H), where H is tree height
// Space O(1)
/**
 * We start from the root, utilizing the property of BST:
 *   - If current node's value is less than or equal to p's value, we know our 
 *     answer must be in the right subtree.
 *   - If current node's value is greater than p's value, current node is a 
 *     candidate. Go to its left subtree to see if we can find a smaller one.
 *   - If we reach null, our search is over, just return the candidate.
 */
class Solution { 
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* candidate = NULL;
        TreeNode* cur = root;

        while(cur) {
            if (cur->val > p->val) {
                candidate = cur;
                cur = cur->left;
            } else {
                // cur->val <= p->val
                cur = cur->right;
            }
        }

        return candidate;
    }
};
