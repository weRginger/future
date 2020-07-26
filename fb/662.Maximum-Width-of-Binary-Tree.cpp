// Time O(n)
// Space O(width)
typedef unsigned long long ull;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        queue<pair<TreeNode*, ull>> q;
        q.push({root, 1});
        while (!q.empty()) {
            if (q.size() == 1) q.front().second = 1;
            ull left = q.front().second, right = left, n = q.size();
            for (int i = 0; i < n; ++i) {
                auto t = q.front().first; 
                right = q.front().second; q.pop();
                if (t->left) q.push({t->left, right * 2});
                if (t->right) q.push({t->right, right * 2 + 1});
            }
            res = max(res, (int)(right - left + 1));
        }
        return res;
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
