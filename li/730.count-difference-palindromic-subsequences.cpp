// Source http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-730-count-different-palindromic-subsequences/

// DP
class Solution2 {
public:
    int countPalindromicSubsequences(const string& S) {
        int n = S.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i)
            dp[i][i] = 1;

        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i < n - len; ++i) {
                const int j = i + len;
                if (S[i] == S[j]) {
                    dp[i][j] = dp[i + 1][j - 1] * 2;
                    int l = i + 1;
                    int r = j - 1;
                    while (l <= r && S[l] != S[i]) ++l;
                    while (l <= r && S[r] != S[i]) --r;
                    if (l == r) dp[i][j] += 1;
                    else if (l > r) dp[i][j] += 2;
                    else dp[i][j] -= dp[l + 1][r - 1];
                } else {
                    dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
                }

                dp[i][j] = (dp[i][j] + kMod) % kMod;
            }
        }

        return dp[0][n - 1];
    }
private:
    static constexpr long kMod = 1000000007;
};

// Recursion with memoization
class Solution {
public:
    int countPalindromicSubsequences(const string& S) {
        const int n = S.length();
        m_ = vector<vector<int>>(n, vector<int>(n, 0));
        return count(S, 0, S.length() - 1);
    }
private:
    static constexpr long kMod = 1000000007;
    long count(const string& S, int s, int e) {
        if (s > e) return 0;
        if (s == e) return 1;
        if (m_[s][e] > 0) return m_[s][e];

        long ans = 0;
        if (S[s] == S[e]) {
            int l = s + 1;
            int r = e - 1;
            while (l <= r && S[l] != S[s]) ++l;
            while (l <= r && S[r] != S[s]) --r;
            if (l > r)
                ans = count(S, s + 1, e - 1) * 2 + 2;
            else if (l == r)
                ans = count(S, s + 1, e - 1) * 2 + 1;
            else
                ans = count(S, s + 1, e - 1) * 2
                      - count(S, l + 1, r - 1);
        } else {
            ans = count(S, s, e - 1)
                  + count(S, s + 1, e)
                  - count(S, s + 1, e - 1);
        }

        return m_[s][e] = (ans + kMod) % kMod;
    }

    vector<vector<int>> m_;
};