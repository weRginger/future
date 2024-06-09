// Time O(n)
// Space O(H) -> could be reduced to O(1) if using Morris traversal. Go to LC for details.
// author ziqi
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});
        while(!q.empty()) {
            auto f = q.front();
            q.pop();
            TreeNode* n = f.first;
            int val = f.second;
            if(n->left) {
                q.push({n->left, 10 * val + n->left->val});
            }
            if(n->right) {
                q.push({n->right, 10 * val + n->right->val});
            }
            if(!n->right && !n->left) {
                sum += val;
            }
        }
        return sum;
    }
};

// Time O(n)
// Space O(H)
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        helper(root, 0);
        return sum;
    }
private:
    int sum = 0;
    void helper(TreeNode* root, int pre) {
        if(!root)
            return;
        if(!root->left && !root->right) {
            sum += pre * 10 + root->val;
            return;
        }
        helper(root->left, pre * 10 + root->val);
        helper(root->right, pre * 10 + root->val);
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
