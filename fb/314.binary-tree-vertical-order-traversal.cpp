// Time O(n)
// Space O(n)
// author ziqi
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        unordered_map<int, vector<int>> mp; // k is the col and v is the values
        int min_col = INT_MAX;
        if(!root) {
            return {};
        }
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            int q_size = q.size();
            for(int i = 0; i < q_size; i++) {
                auto p = q.front();
                mp[p.second].push_back(p.first->val);
                min_col = min(min_col, p.second);
                if(p.first->left) {
                    q.push({p.first->left, p.second-1});
                }
                if(p.first->right) {
                    q.push({p.first->right, p.second+1});
                }
                q.pop();
            }
        }

        vector<vector<int>> ans;
        while(mp.count(min_col)) {
            ans.push_back(mp[min_col]);
            min_col++;
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
