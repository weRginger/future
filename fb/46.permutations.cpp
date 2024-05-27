// Time O(n * n!)
// Space O(n!)
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> visited(nums.size(), false);
        helper(nums, curr, ans, visited);
        return ans;
    }
private:
    void helper (const vector<int>& nums,
                 vector<int>& curr,
                 vector<vector<int>>& ans,
                 vector<bool>& visited) {
        
        if(curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }
            
        for(int i = 0; i < nums.size(); i++) {
            if(!visited[i]) {
                visited[i] = true;
                curr.push_back(nums[i]);
                helper(nums, curr, ans, visited);
                curr.pop_back();
                visited[i] = false;
            }
        }
    }
};
