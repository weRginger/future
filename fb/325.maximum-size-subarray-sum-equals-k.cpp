class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int max_length = 0;

        // accumulate the sum
        for (int i = 1; i < nums.size(); ++i) {
            nums[i] += nums[i - 1];
        }

        unordered_map<int, int> sums;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == k) {
                max_length = i + 1;
            } else if (sums.find(nums[i] - k) != sums.end()) {
                max_length = max(max_length, i - sums[nums[i] - k]);
            }
            if (sums.find(nums[i]) == sums.end()) {
                sums[nums[i]] =  i;
            }
        }
        return max_length;
    }
};