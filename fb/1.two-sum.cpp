class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> s;
        for(int i = 0; i < nums.size(); i++) {
            if(!s.count(nums[i])) {
                s[target - nums[i]] = i;
            }
            else {
                ans.push_back(s[nums[i]]);
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};