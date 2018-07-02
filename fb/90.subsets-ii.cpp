class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(nums.empty()) return vector<vector<int>>();
        vector<vector<int>> ans;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        helper(nums, 0, ans, cur);
        return ans;
    }
private:
    void helper(vector<int>& nums, int idx, vector<vector<int>>& ans, vector<int>& cur) {
        ans.push_back(cur);
        for(int i = idx; i < nums.size(); i++) {
            if(i > idx && nums[i] == nums[i - 1])
                continue;
            cur.push_back(nums[i]);
            helper(nums, i + 1, ans, cur);
            cur.pop_back();
        }
    }
};