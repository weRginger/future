// Time O(n)
// Space O(1)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int start = 0;
        int sum = 0;
        for (int end = 0; end < n; end++) {
            sum += nums[end];
            while (sum >= s) {
                ans = min(ans, end + 1 - start);
                sum -= nums[start++];
            }
        }
        return (ans != INT_MAX) ? ans : 0;
    }
};
