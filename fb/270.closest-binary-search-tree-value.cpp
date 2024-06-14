// Time O(H), where H is tree height
// Space O(1)
// author ziqi
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int ans = root->val;
        while(root) {
            // early stop since no other value would be closer to target for sure,
            // since all root->val are int
            if(abs(target - root->val) < 0.5) {
                return root->val;
            }
            if(abs(target - root->val) < abs(target - ans)) {
                ans = root->val;
            } else if(abs(target - root->val) == abs(target - ans)) {
                if(root->val < ans) {
                    ans = root->val;
                }
            }
            if(root->val > target) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return ans;
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
