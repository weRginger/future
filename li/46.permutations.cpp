class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.empty()) return ans;
        vector<bool> visited(nums.size(), false);
        vector<int> curr;
        helper(nums, ans, curr, visited);
        return ans;
    }
private:
    void helper(const vector<int>& nums, vector<vector<int>>& ans, vector<int>& curr, vector<bool>& visited) {
        if(curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(visited[i] == false) {
                curr.push_back(nums[i]);
                visited[i] = true;
                helper(nums, ans, curr, visited);
                visited[i] = false;
                curr.pop_back();
            }
        }
    }
};
