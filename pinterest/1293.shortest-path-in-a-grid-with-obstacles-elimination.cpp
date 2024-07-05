// Time complexity: O(m*n*k)
// Space complexity: O(m*n*k)
// State: (x, y, k) where k is the number of obstacles along the path.
// author: huahua https://www.youtube.com/watch?v=VpEEtzIMOKg
class Solution {
public:
  int shortestPath(vector<vector<int>>& grid, int k) {
    // must iterate 4 directions instead of only going right or down
    const vector<int> dirs{0, 1, 0, -1, 0}; 
    const int n = grid.size();
    const int m = grid[0].size();
    // seen[i][j] = val means the smallest number of obstacles encountered to reach grid[i][j]
    vector<vector<int>> seen(n, vector<int>(m, INT_MAX));
    queue<tuple<int, int, int>> q; 
    int steps = 0;
    q.emplace(0, 0, 0);
    seen[0][0] = 0;
    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        int cx, cy, co;
        tie(cx, cy, co) = q.front(); q.pop();         
        if (cx == m - 1 && cy == n - 1) return steps;
        for (int i = 0; i < 4; ++i) {
          int x = cx + dirs[i];
          int y = cy + dirs[i + 1];
          if (x < 0 || y < 0 || x >= m || y >= n) continue;
          int o = co + grid[y][x];
          if (o >= seen[y][x] || o > k) continue;
          // means we see a path encountering less obstacles, which is more promissing.
          // so we should try to expanding from it            
          seen[y][x] = o; 
          q.emplace(x, y, o);
        }
      }
      ++steps;
    }
    return -1;
  }
};
