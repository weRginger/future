// Time O(H), where H is tree height
// Space O(1)
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int closest = root->val;
        while(root) {
            int val = root->val;
            if(val == target)
                return val;
            closest = abs(val - target) < abs(closest - target) ? val : closest;
            root =  target < root->val ? root->left : root->right;
        }
        return closest;
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
