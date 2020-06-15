class Solution {
    vector<int> dr{1, -1, 0, 0};
    vector<int> dc{0, 0, 1, -1};
    int empty = 0;
    int ans = 0;
    int rs, cs;
    bool isValid(int r, int c) {
        if(r < 0 || r >= rs || c < 0 || c >= cs) return false;
        return true;
    }
    void helper(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c, int count) {
        if(grid[r][c] == 2 && count - 1 == empty) ans++;
        for(int i = 0; i < 4; i++) {
            int r_next = r + dr[i];
            int c_next = c + dc[i];
            if(isValid(r_next, c_next) && grid[r_next][c_next] != -1 && visited[r_next][c_next] == false) {
                visited[r_next][c_next] = true;
                helper(grid, visited, r_next, c_next, count + 1);
                visited[r_next][c_next] = false;
            }
        }
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        rs = grid.size();
        cs = grid[0].size();
        vector<vector<bool>> visited(rs, vector<bool>(cs, false));
        for(int i = 0; i < rs; i++) {
            for(int j = 0; j < cs; j++) {
                if(grid[i][j] == 0) empty++;
            }
        }
        for(int i = 0; i < rs; i++) {
            for(int j = 0; j < cs; j++) {
                if(grid[i][j] == 1) {
                    visited[i][j] = true;
                    helper(grid, visited, i, j, 0);
                }
            }
        }
        return ans;
    }
};
