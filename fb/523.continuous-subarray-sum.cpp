class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.empty()) return false;
        unordered_map<int, int> sum2Idx;
        int sum = 0;
        sum2Idx[sum] = -1;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(k != 0)
                sum %= k;
            if(sum2Idx.count(sum)) {
                if(i - sum2Idx[sum] >= 2) {
                    return true;
                }
            }
            else
                sum2Idx[sum] = i;
        }
        return false;
    }
};