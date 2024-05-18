#define INF 100007

class Solution {
    int n,m;
    bool isValid(int x, int y) {
        if (x < 0 || y < 0 || x >= n || y >= m) return false;
        return true;
    }
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    int dp[41][41][41*41];
    int vis[41][41][41*41];

public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        memset(dp, -1, sizeof dp);
        memset(vis, -1, sizeof vis);
        int ans = solve(grid, k, 0, 0);
        if(ans == INF) return -1;
        return ans;
    }
    
    int solve(vector<vector<int>>& a, int k,int i, int j) {
        if(i == n - 1 && j == m - 1) {
            return 0;
        }
        if(dp[i][j][k] != -1) return dp[i][j][k];        
        int ans = INF;
        for(int K = 0; K < 4; K++) {
            int x = dx[K] + i;
            int y = dy[K] + j;
            if(isValid(x,y) && vis[i][j][k] == -1) {
                vis[i][j][k] = 1;
                if(a[x][y] == 0) {
                    ans = min(ans, 1 + solve(a, k, x, y));
                } else if(k > 0) {
                    ans = min(ans, 1 + solve(a, k -1, x, y));
                }
                vis[i][j][k] = -1;
            }
        } 
        dp[i][j][k] = ans;
        return ans;
    }
};
