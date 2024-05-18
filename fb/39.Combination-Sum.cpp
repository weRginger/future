// Time, not sure, O(n^n)?
// Space O(n)
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        std::sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, cur, ans);
        return ans;
    }
private:
    void dfs(const vector<int>& candidates, int target, int s, vector<int>& cur, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        }
        
        for (int i = s; i < candidates.size(); ++i) {
            if (candidates[i] > target) break;
            cur.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, cur, ans);
            cur.pop_back();
        }
    }
};
