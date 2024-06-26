// bfs
// Time O(n)
// Space O(H)
// author ziqi
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if(cur->val >= low && cur->val <= high) {
                ans += cur->val;
            }
            if(cur->val > low && cur->left) {
                q.push(cur->left);
            }
            if(cur->val < high && cur->right) {
                q.push(cur->right);
            }
        }
        return ans;
    }
};

// dfs
// Time O(n)
// Space O(H)
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int ans = 0;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();
            if (node) {
                if (L <= node->val && node->val <= R)
                    ans += node->val;
                if (L < node->val)
                    stk.push(node->left);
                if (node->val < R)
                    stk.push(node->right);
            }
        }
        return ans;
    }
};

// Time O(n)
// Space O(H)
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        int ans = 0;
        if(root->val >= low && root->val <= high) {
            ans += root->val;
            ans += rangeSumBST(root->left, low, high);
            ans += rangeSumBST(root->right, low, high);
        } else if(root->val > high) {
            ans += rangeSumBST(root->left, low, high);
        } else {
            ans += rangeSumBST(root->right, low, high);
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
