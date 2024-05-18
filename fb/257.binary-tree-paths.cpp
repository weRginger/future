// Time O(n)
// Space O(n)
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root) return ans;
        binaryTreePaths(root, ans, "");
        return ans;
    }

private:
    void binaryTreePaths(TreeNode* root, vector<string>& paths, string path) {
        if(!root->left && !root->right) {
            path += to_string(root->val);
            paths.push_back(path);
            return;
        }
        path += to_string(root->val) + "->";
        if(root->left)
            binaryTreePaths(root->left, paths, path);
        if(root->right)
            binaryTreePaths(root->right, paths, path);
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
