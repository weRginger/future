// Time O(l*n). The memo array of size l*n has been filled just once. Here, l refers to the range of sumsum and n refers to the size of nums array.
// Space O(l*n). The depth of recursion tree can go upto n. The memo array contains l*n elements.
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        unordered_map<int, unordered_map<int, int>> memo;
        return helper(nums, S, 0, memo);
    }
private:
    int helper(const vector<int>& nums, long left, int idx,
               unordered_map<int, unordered_map<int, int>> &memo) {
        if(idx > nums.size())
            return 0;
        if(idx == nums.size())
            return left == 0? 1 : 0;
        if(memo.count(left) && memo[left].count(idx))
            return memo[left][idx];
        int ans = helper(nums, left+nums[idx], idx+1, memo);
        ans += helper(nums, left-nums[idx], idx+1, memo);
        return memo[left][idx] = ans;
    }
};
