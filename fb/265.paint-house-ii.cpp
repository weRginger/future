class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        int n = costs.size(), k = costs[0].size(), m1 = 0, m2 = 0;
        vector<int> dp(k, 0);
        for (int i = 0; i < n; i++) {
            int t1 = m1, t2 = m2;
            m1 = m2 = INT_MAX;
            for (int j = 0; j < k; j++) {
                dp[j] = (dp[j] != t1 ? t1 : t2) + costs[i][j];
                if (dp[j] < m1) m2 = m1, m1 = dp[j];
                else m2 = min(m2, dp[j]);
            }
        }
        return m1;
    }
};
