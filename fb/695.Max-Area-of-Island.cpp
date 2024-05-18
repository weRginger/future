// Time O(mn)
// Time O(mn)
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        m = grid.size();
        n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    int count = 1;
                    dfs(grid, count, i, j);
                    maxArea = max(maxArea, count);
                }
            }
        }
        return maxArea;
    }
private:
    int m, n;
    int maxArea = 0;
    const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    bool isValid(const vector<vector<int>>& grid, int x, int y) {
        if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1)
            return true;
        return false;
    }
    
    void dfs(vector<vector<int>>& grid, int& count, int x, int y) {
        grid[x][y] = -1;
        for(auto d : dirs) {
            int X = x + d[0];
            int Y = y + d[1];
            if(isValid(grid, X, Y)) {
                dfs(grid, ++count, X, Y);
            }
        }
    }
};
