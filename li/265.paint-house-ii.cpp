// Time: O(k*n); Space: O(1)
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty()) 
            return 0;
        if (costs[0].empty()) 
            return 0;
        int smallest = INT_MAX;
        int smallest_index = -1;
        int second_smallest = INT_MAX;
        for (int i = 0; i < costs[0].size(); i++) {
            if (costs[0][i] < smallest) {
                second_smallest = smallest;
                smallest = costs[0][i];
                smallest_index = i;
            } else if (costs[0][i] < second_smallest) {
                second_smallest = costs[0][i];
            }
        }

        for (int i = 1; i < costs.size(); i++) {
            int _smallest = INT_MAX;
            int _smallest_index = -1;
            int _second_smallest = INT_MAX;
            for (int j = 0; j < costs[i].size(); j++) {
                int curr = costs[i][j] + (smallest_index == j ? second_smallest : smallest);
                if (curr < _smallest) {
                    _second_smallest = _smallest;
                    _smallest = curr;
                    _smallest_index = j;
                } else if (curr < _second_smallest) {
                    _second_smallest = curr;
                }
            }
            smallest = _smallest;
            smallest_index = _smallest_index;
            second_smallest = _second_smallest; 
        }
        return smallest;        
    }
};

// Time: O(kn); Space: O(k)
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
