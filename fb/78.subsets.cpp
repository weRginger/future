// Bit mask
// Time O(2^n)
// Space O(n)
class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    const int n = nums.size();
    vector<vector<int>> ans;    
    for (int s = 0; s < 1 << n; ++s) {
      vector<int> cur;
      for (int i = 0; i < n; ++i)
        if (s & (1 << i)) cur.push_back(nums[i]);
      ans.push_back(cur);
    }
    return ans;
  }
};

// DFS
// Time O(2^n)
// Space O(n)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.empty()) return vector<vector<int>>();
        vector<vector<int>> ans;
        vector<int> cur;
        helper(nums, 0, ans, cur);
        return ans;
    }
private:
    void helper(vector<int>& nums, int idx, vector<vector<int>>& ans, vector<int>& cur) {
        ans.push_back(cur);
        for(int i = idx; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            helper(nums, i + 1, ans, cur);
            cur.pop_back();
        }
    }
};
