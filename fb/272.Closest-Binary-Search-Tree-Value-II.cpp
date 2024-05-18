// Time O(logN + K)
// Space O(logN)
class Solution {
private:
    void pushStack(TreeNode* node, double target, stack<TreeNode*>& pred, stack<TreeNode*>& succ) {
        while (node) {
            if (target <= node->val) {
                succ.push(node);
                node = node->left;
            } else {
                pred.push(node);
                node = node->right;
            }
        }
    }
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        stack<TreeNode*> pred, succ;
        // two stacks would both be pushed
        pushStack(root, target, pred, succ);
        while (k-- > 0) {
            if (succ.empty() || !pred.empty() &&
                abs(pred.top()->val - target) < abs(succ.top()->val - target) ) {
                TreeNode* temp = pred.top();
                res.push_back(temp->val);
                pred.pop();
                // only pred stack would be pushed
                pushStack(temp->left, target, pred, succ);
            } else {
                TreeNode* temp = succ.top();
                res.push_back(temp->val);
                succ.pop();
                // only succ stack would be pushed
                pushStack(temp->right, target, pred, succ);
            }
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
