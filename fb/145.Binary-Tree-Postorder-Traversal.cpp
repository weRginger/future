// iterative
// Time O(n)
// Space O(H), where H is tree height
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> output;
        stack<TreeNode*> stk;
        
        if (root == nullptr) return output;

        stk.push(root);
        while(!stk.empty()) {
            root = stk.top();
            stk.pop();
            output.push_back(root->val);
            if(root->left) stk.push(root->left);
            if(root->right) stk.push(root->right);
        }

        reverse(output.begin(), output.end());
        return output;
    }
};

// recursive
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
private:
    void postorder(TreeNode* root, vector<int>& ans) {
        if(!root)
            return;
        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
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
