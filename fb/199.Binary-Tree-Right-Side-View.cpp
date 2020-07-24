// Time O(n)
// Space O(width)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> layer;
        layer.push(root);
        while (layer.size()) {
            res.push_back(layer.front()->val);
            int len = layer.size();
            while (len--) {
                TreeNode* currNode = layer.front();
                layer.pop();
                if (currNode->right) layer.push(currNode->right);
                if (currNode->left) layer.push(currNode->left);
            }
        }
        return res;
    }
};
