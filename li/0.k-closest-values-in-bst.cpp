#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> cloestKValues(TreeNode* root, double target, int k) {
        vector<int> ans;
        if(!root || k < 0) return ans;
        helper(root, target, k, ans);
        return ans;
    }

private:
    void helper(TreeNode* node, double target, int k, vector<int>& ans) {
        if(!node) return;
        helper(node->left, target, k, ans);
        if(ans.size() < k) {
            ans.push_back(node->val);
        }
        else {
            double diff = abs(target - node->val);
            double oldDiff = abs(target - ans[0]);
            if(diff < oldDiff) {
                ans.erase(ans.begin());
                ans.push_back(node->val);
            }
            else {
                // terminate early since the rest values will be even larger
                return;
            }
        }
        helper(node->right, target, k, ans);
    }
};

