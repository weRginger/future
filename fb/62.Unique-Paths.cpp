// Time O(mn)
// Space O(min(m,n))
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for(int i = 1; i < m; i++) {
            int left = 1;
            for(int j = 1; j < n; j++) {
                dp[j] = left + dp[j];
                left = dp[j];
                // above two lines of code could be replaced as 
                // dp[j] = dp[j-1] + dp[j];
                // since left == dp[j-1] (only 1 way, which is going down) 
            }
        }
        return dp[n-1];
    }
};
