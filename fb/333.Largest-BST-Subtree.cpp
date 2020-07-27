// Time O(n)
// Space O(H)
// 全是细节！
class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        vector<int> res = helper(root);
        return res[2];
    }
    
private:
    // return[0] is smallest number in the subtree
    // return[1] is largest number in the subtree
    // return[2] is valid node count in the subtree
    vector<int> helper(TreeNode* node) {
        if (!node) return {INT_MAX, INT_MIN, 0};
        vector<int> left = helper(node->left), right = helper(node->right);
        if (node->val > left[1] && node->val < right[0]) {
            return {min(node->val, left[0]), max(node->val, right[1]), left[2] + right[2] + 1};
        } else {
            return {INT_MIN, INT_MAX, max(left[2], right[2])};
        }
    }
};
