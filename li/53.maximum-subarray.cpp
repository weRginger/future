// Time O(n), space O(1)
// We need to convert this problem into two steps: find maxSunArrayEndingInNums[i] then find the largest, so
// Step1: dp[i] denotes the largest sum of subarray ending with nums[i], i.e. must contain nums[i].
// Step2: along the dp process, we need to find the largest dp[i], which will be the find answer.
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int ans = nums[0];
        int dp = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            dp = max(dp + nums[i], nums[i]);
            ans = max(ans, dp);
        }
        return ans;
    }
};
