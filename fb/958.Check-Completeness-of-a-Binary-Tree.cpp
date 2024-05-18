// Time O(n)
// Space O(width)
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        bool seennull=false;
        while (!que.empty()) {
            TreeNode* curr=que.front(); que.pop();
            if (curr==NULL) {
                if (!seennull) seennull=true;
                continue;
            }
            else if (seennull) return false;
            que.push(curr->left);
            que.push(curr->right);            
        }
        return true;
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
