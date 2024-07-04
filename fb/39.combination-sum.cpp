// Time, not sure, O(n^n)?
// Space O(n)
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        if(candidates.empty()) return ans;
        sort(candidates.begin(), candidates.end()); // sort and left > 0 for early termination
        vector<int> curr;
        helper(candidates, target, 0, curr, ans);
        return ans;
    }
    void helper(vector<int>& candidates, int left, int idx, vector<int>& curr, vector<vector<int>>& ans) {
        if(left == 0) {
            ans.push_back(curr);
            return;
        }
        for(int i = idx; i < candidates.size() && left > 0; i++) {
            curr.push_back(candidates[i]);
            helper(candidates, left - candidates[i], i, curr, ans);
            curr.pop_back();
        }
    }
};
