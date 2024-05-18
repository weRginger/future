class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> ans;
        vector<int> cur;
        helper(n, ans, cur, 2);
        return ans;
    }
    void helper(int n, vector<vector<int>>& ans, vector<int>& cur, int num) {
        int s = sqrt(n);
        for(int i = num; i <= s; i++) {
            if(n % i == 0) {
                cur.push_back(i);
                cur.push_back(n / i);
                ans.push_back(cur);
                cur.pop_back();
                helper(n / i, ans, cur, i);
                cur.pop_back();
            }
        }
    }
};