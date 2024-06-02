// Let n be the number of array elements and m be the subSetSum.
// Time O(m⋅n)
// Space O(m⋅n). If use DP, could be O(m)
class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int totalSum = 0;
        // find sum of all array elements
        for (int num : nums) {
            totalSum += num;
        }
        // if totalSum is odd, it cannot be partitioned into equal sum subset
        if (totalSum % 2 != 0) return false;
        int subSetSum = totalSum / 2;
        int n = nums.size();
        vector<vector<optional<bool>>> memo(n + 1, vector<optional<bool>>(subSetSum + 1, nullopt));
        return dfs(nums, n - 1, subSetSum, memo);
    }

    bool dfs(vector<int> &nums, int n, int subSetSum, vector<vector<optional<bool>>> &memo) {
        // Base Cases
        if (subSetSum == 0)
            return true;
        if (n == 0 || subSetSum < 0)
            return false;
        // check if subSetSum for given n is already computed and stored in memo
        if (memo[n][subSetSum] != nullopt) {
            return (memo[n][subSetSum] == true);
        }
        bool result = dfs(nums, n - 1, subSetSum - nums[n - 1], memo) || // select nums[n-1]
                dfs(nums, n - 1, subSetSum, memo); // not select nums[n-1]
        return memo[n][subSetSum] = result;
    }
};
