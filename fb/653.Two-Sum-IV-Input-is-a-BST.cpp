// Time O(n)
// Space O(n)
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        inorder(root, v);
        int l = 0, r = v.size() - 1;
        while (l < r) {
            int sum = v[l] + v[r];
            if (sum == k)
                return true;
            if (sum < k)
                l++;
            else
                r--;
        }
        return false;
    }
private:
    void inorder(TreeNode* root, vector<int>& v) {
        if(!root) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
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
