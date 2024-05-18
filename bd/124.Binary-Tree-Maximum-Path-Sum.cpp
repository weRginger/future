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
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        max_gain(root);
        return max_sum;
    }
private:
    int max_sum = INT_MIN;
    int max_gain(TreeNode* node) {
        if (node == NULL) return 0;

        // max sum on the left and right sub-trees of node
        int left_gain = max(max_gain(node->left), 0);
        int right_gain = max(max_gain(node->right), 0);

        // the price to start a new path where `node` is a highest node
        int price_newpath = node->val + left_gain + right_gain;

        // update max_sum if it's better to start a new path
        max_sum = max(max_sum, price_newpath);

        // for recursion :
        // return the max gain if continue the same path
        return node->val + max(left_gain, right_gain);
    }
};
