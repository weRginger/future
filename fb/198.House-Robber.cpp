// Time O(n)
// Space O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        int S = nums.size();
        if(S == 1) return nums[0];
        int pre = nums[0];
        int ans = max(nums[0], nums[1]);
        for(int i = 2; i < S; i++) {
            int tmp = ans;
            ans = max(nums[i] + pre, ans);
            pre = tmp;
        }
        return ans;
    }
};
