// Source: http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-377-combination-sum-iv/
// Recursive with Memoization
// Runtime: 0 ms
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        m_ = vector<int>(target + 1, -1);
        return dp(nums, target);
    }
private:
    int dp(const vector<int>& nums, int target) {
        if(target < 0) return 0;
        if(target == 0) return 1;
        if(m_[target] != -1) return m_[target];
        int ans = 0;
        for(const int num : nums)
            ans += dp(nums, target - num);
        return m_[target] = ans;
    }
    vector<int> m_;
};

// DP
// Runtime: 3 ms
class Solution2 {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0); // dp[i] # of combinations sum up to i
        dp[0] = 1;
        for (int i = 1; i <= target; ++i)
            for (const int num : nums)
                if (i - num >= 0)
                    dp[i] += dp[i - num];
        return dp[target];
    }
};