class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        int ans = 1;
        for(int i = 1, cur = 1; i < nums.size(); i++) {
            if(nums[i] > nums[i-1]) {
                cur++;
                ans = max(ans, cur);
            }
            else {
                cur = 1;
            }
        }
        return ans;
    }
};
