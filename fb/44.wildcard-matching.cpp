class Solution {
public:
    bool isMatch(string s, string p) {
        int S = s.size(), P = p.size();
        vector<vector<bool>> dp(S + 1, vector<bool>(P + 1, false));
        dp[0][0] = true;
        for (int i = 0; i < P; i++) {
            if (p[i] == '*' && dp[0][i])
                dp[0][i + 1] = true; // empty
        }
        for (int i = 0; i < S; i++) {
            for (int j = 0; j < P; j++) {
                if (s[i] == p[j] || p[j] == '?')
                    dp[i + 1][j + 1] = dp[i][j];
                if (p[j] == '*')
                    dp[i + 1][j + 1] = dp[i][j + 1] || dp[i + 1][j]; // multipe || empty
            }
        }
        return dp[S][P];
    }
};