// dfs
// Time O(m*n)
// Space O(m*n)
class Solution {
private:
    vector<int> rd = {-1, 0, 1, 0};
    vector<int> cd = {0, 1, 0, -1};
     void dfs(vector<vector<char>>& grid, const int& m, const int& n, const int& r, const int& c) {
        grid[r][c] = '0';
        for(int i = 0; i < 4; i++) {
            int nr = r + rd[i];
            int nc = c + cd[i];
            if(nr >= 0 && nr < m && nc >=0 && nc < n && grid[nr][nc] == '1') {
                dfs(grid, m, n, nr, nc);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for(int i = 0; i < m; i++) {
            for(int j =0; j < n; j++) {
                if(grid[i][j] == '1') {
                    count++;
                    dfs(grid, m, n, i, j);
                }
            }
        }
        return count;
    }
};

// bfs
// Time O(m*n)
// Space O(min(m,n))
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        int num_islands = 0;
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    ++num_islands;
                    grid[r][c] = '0'; // mark as visited
                    queue<pair<int, int>> neighbors;
                    neighbors.push({r, c});
                    while (!neighbors.empty()) {
                        auto rc = neighbors.front();
                        neighbors.pop();
                        int row = rc.first, col = rc.second;
                        if (row - 1 >= 0 && grid[row-1][col] == '1') {
                            neighbors.push({row-1, col});
                            grid[row-1][col] = '0';
                        }
                        if (row + 1 < nr && grid[row+1][col] == '1') {
                            neighbors.push({row+1, col});
                            grid[row+1][col] = '0';
                        }
                        if (col - 1 >= 0 && grid[row][col-1] == '1') {
                            neighbors.push({row, col-1});
                            grid[row][col-1] = '0';
                        }
                        if (col + 1 < nc && grid[row][col+1] == '1') {
                            neighbors.push({row, col+1});
                            grid[row][col+1] = '0';
                        }
                    }
                }
            }
        }

        return num_islands;
    }
};

// union find
// Time O(m*n)
// Space O(m*n)
class UnionFind {
public:
    UnionFind(vector<vector<char>>& grid) {
        count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    parent.push_back(i * n + j);
                    ++count;
                }
                else parent.push_back(-1);
                rank.push_back(0);
            }
        }
    }

    int find(int i) { // path compression
        if (parent[i] != i) parent[i] = find(parent[i]);
        return parent[i];
    }

    void Union(int x, int y) { // union with rank
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] > rank[rooty]) parent[rooty] = rootx;
            else if (rank[rootx] < rank[rooty]) parent[rootx] = rooty;
            else {
                parent[rooty] = rootx;
                rank[rootx] += 1;
            }
            --count;
        }
    }

    int getCount() const {
        return count;
    }

private:
    vector<int> parent;
    vector<int> rank;
    int count; // # of connected components
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        UnionFind uf (grid);
        int num_islands = 0;
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    grid[r][c] = '0';
                    if (r - 1 >= 0 && grid[r-1][c] == '1') uf.Union(r * nc + c, (r-1) * nc + c);
                    if (r + 1 < nr && grid[r+1][c] == '1') uf.Union(r * nc + c, (r+1) * nc + c);
                    if (c - 1 >= 0 && grid[r][c-1] == '1') uf.Union(r * nc + c, r * nc + c - 1);
                    if (c + 1 < nc && grid[r][c+1] == '1') uf.Union(r * nc + c, r * nc + c + 1);
                }
            }
        }

        return uf.getCount();
    }
};
