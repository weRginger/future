// Time O(n)
// Space O(n)
// BFS and found out the first and last nodes of the deepest level. Then LCA of that two nodes will be answer.
class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root) return nullptr;
        deque<TreeNode*> q;
        q.push_back(root);
        TreeNode* first = root;
        TreeNode* last = root;
        while(!q.empty()) {
            int S = q.size();
            for(int i = 0; i < S; i++) {
                TreeNode* curr = q.front(); q.pop_front();
                if(curr->left) q.push_back(curr->left);
                if(curr->right) q.push_back(curr->right);
            }
            if(!q.empty()) {
                first = q.front();
                last = q.back();
            }
        }
        
        return LCA(root, first, last);
    }
    
private:
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) {
            return root;
        }
        TreeNode* left = LCA(root->left, p, q);
        TreeNode* right = LCA(root->right, p, q);
        if(left && right)
            return root;
        if(!left)
            return right;
        return left;
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
