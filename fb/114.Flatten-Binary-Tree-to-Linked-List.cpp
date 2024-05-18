// Time O(n)
// Space O(1)
class Solution {
public:
    void flatten(TreeNode* root) {
        // Handle the null scenario
        if(!root) return;
        
        while(root) {
            // If the node has a left child
            if(root->left) {
                // Find the rightmost node
                TreeNode* rightmost = root->left;
                while(rightmost->right)
                    rightmost = rightmost->right;
                
                // rewire the connections
                rightmost->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            
            // move on to the next node
            root = root->right;
        }
    }
};

// Time O(n)
// Space O(n)
// Author: Ziqi
class Solution {
private:
    stack<TreeNode*> stk;
    
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        if(root->right) stk.push(root->right);
        if(root->left) stk.push(root->left);
        while(!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();
            root->right = node;
            root->left = NULL;
            if(node->right) stk.push(node->right);
            if(node->left) stk.push(node->left);
            root = node;
        }
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
