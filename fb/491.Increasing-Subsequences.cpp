// Time O(2^n)
// Space O(n)
class Solution {
public:
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> cur;
    dfs(nums, 0, cur, ans);
    return ans;
  }
private:
  void dfs(const vector<int>& nums, int s, vector<int>& cur, vector<vector<int>>& ans) {    
    unordered_set<int> seen;
    for (int i = s; i < nums.size(); ++i) {
      if (!cur.empty() && nums[i] < cur.back()) continue;
      // each number can be used only once at the same depth.
      if (seen.count(nums[i])) continue; 
      seen.insert(nums[i]);
      cur.push_back(nums[i]);
      if (cur.size() > 1) 
        ans.push_back(cur);
      dfs(nums, i + 1, cur, ans);
      cur.pop_back();
    }
  }
};
