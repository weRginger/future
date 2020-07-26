// Time O(mn)
// Space O(min(m,n))
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1) return 1;
        vector<int> up(n, 1);
        int left = 1;
        int ans = 0;
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(j == 1) left = 1;
                ans = left + up[j];
                up[j] = ans;
                left = ans;
            }
        }
        return ans;
    }
};
