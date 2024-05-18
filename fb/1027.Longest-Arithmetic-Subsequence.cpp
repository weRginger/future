/*
动态规划，dp[diff][idx]表示等差为diff，以系数idx结尾的最长子序列长度。dp[diff][idx]最初都为0，但凡遍历到的最小则为2。
双重循环，外循环系数i，内循环系数j，每一次我们让j从0走到i-1，通过A[j]与A[i]组成等差数列(diff = A[i] - A[j])，更新
dp[diff][i]的值为：max(dp[diff][j] + 1, dp[diff][i])，同时更新返回值res = max(res, dp[diff][i])。最后返回res即可。
https://xingxingpark.com/Leetcode-1027-Longest-Arithmetic-Sequence/
*/
// Time O(n^2)
// Space O(n^2)
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        unordered_map<int, unordered_map<int, int>> dp;
        if (A.size() <= 1) {
            return A.size();
        }
        int res = 2;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                int diff = A[i] - A[j];
                if (!dp[diff].count(i)) {
                    dp[diff][i] = 2;
                }
                dp[diff][i] = max(dp[diff][j] + 1, dp[diff][i]);
                res = max(res, dp[diff][i]);
            }
        }
        return res;
    }
};
