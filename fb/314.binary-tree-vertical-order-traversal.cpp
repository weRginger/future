// Time O(n)
// Space O(n)
// author ziqi
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root) return {};
        int left_most = 0;
        unordered_map<int, vector<int>> level_to_values;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            auto cur = q.front();
            int lvl = cur.second;
            TreeNode* node = cur.first;
            q.pop();
            level_to_values[lvl].push_back(node->val);
            if(node->left) {
                q.push({node->left, lvl - 1});
                left_most = min(left_most, lvl-1);
            }
            if(node->right) {
                q.push({node->right, lvl + 1});
            }
        }
        vector<vector<int>> ans;
        while(level_to_values.count(left_most)) {
            ans.push_back(level_to_values[left_most++]);
        }
        return ans;
    }
};

// Time O(n)
// Space O(n)
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        unordered_map<int, vector<int>> cols;
        queue<pair<TreeNode*, int>> q;
        int minIndex = INT_MAX;
        int maxIndex = INT_MIN;
        if(root)
            q.emplace(root, 0);
        while(!q.empty()) {
            auto node = q.front().first;
            int x = q.front().second;
            minIndex = min(minIndex, x);
            maxIndex = max(maxIndex, x);
            q.pop();
            cols[x].push_back(node->val);
            if (node->left)
                q.emplace(node->left, x-1);
            if (node->right)
                q.emplace(node->right, x+1);
        }
        vector<vector<int>> result;
        // This can work since all the values between minIndex and maxIndex (inclusive) 
        // must exist in the unordered_map due to binary tree structure
        for(int i = minIndex; i < maxIndex + 1; i++)
            result.push_back(cols[i]);
        return result;
    }
};

// Time O(nlogn)
// Space O(n)
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> cols;
        queue<pair<TreeNode*, int>> q;
        if (root)
            q.emplace(root, 0);
        while (!q.empty()) {
            auto node = q.front().first;
            int x = q.front().second;
            q.pop();
            cols[x].push_back(node->val);
            if (node->left)
                q.emplace(node->left, x-1);
            if (node->right)
                q.emplace(node->right, x+1);
        }
        vector<vector<int>> result;
        for (auto col : cols)
            result.push_back(col.second);
        return result;
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
