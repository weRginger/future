class Solution {
private:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, -1, 0, 1};
    int N;

    void dfs(vector<vector<int>>& grid, int r, int c, int index, int& ans) {
        grid[r][c] = index;
        for(auto n : neighbors(r, c)) {
            if(grid[n/N][n%N] == 1) { // implicitly marked as visited
                grid[n/N][n%N] = index;
                ans += 1;
                dfs(grid, n/N, n%N, index, ans);
            }
        }
    }

    vector<int> neighbors(int r, int c) {
        vector<int> ans;
        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr > -1 && nr < N && nc > -1 && nc < N) {
                ans.push_back(nr * N + nc);
            }
        }
        return ans;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        N = grid.size();

        // mark each island with an index and calculate its area
        int index = 2;
        unordered_map<int, int> areas; // k starts from 2 since 0 and 1 are used by the original input
        for(int r = 0; r < N; r++) {
            for(int c = 0; c < N; c++) {
                if(grid[r][c] == 1) {
                    int area = 1;
                    dfs(grid, r, c, index, area);
                    areas[index++] = area;
                }
            }
        }

        int ans = 0;

        // find the max without flip 0 to 1
        for(auto area: areas) {
            ans = max(ans, area.second);
        }

        // find the max by flipping 0 to 1
        for(int r = 0; r < N; r++) {
            for(int c = 0; c < N; c++) {
                if(grid[r][c] == 0) {
                    unordered_set<int> seen;
                    for(auto n : neighbors(r, c)) {
                        if(grid[n/N][n%N] > 1) {
                            seen.insert(grid[n/N][n%N]);
                        }
                    }
                    int tmp = 1; // the current point
                    for(auto i : seen) {
                        tmp += areas[i];
                    }
                    ans = max(ans, tmp);
                }
            }
        }

        return ans;
    }
};
