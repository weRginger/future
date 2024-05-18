// Let dp[i][j] denote the number of common suffix of two substrings of S - one up to i, and one up to j (j < i).
// When j and i are pointing to the same char, dp[i][j] = dp[i-1][j-1]+1.
// Maintain the maximum.
// Time O(n^2)
// Space O(n^2)
class Solution {
public:
    int longestRepeatingSubstring(string S) {
        if(S.empty()){
            return 0;
        }

        int n = S.size();
        int res = 0;

        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<i; j++){
                if(S[i-1] == S[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                    res = max(res, dp[i][j]);
                }
            }
        }

        return res;
    }
};
