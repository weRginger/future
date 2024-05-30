// Time O(mn). Each vertex/cell will be calculated once and only once, and each edge will be 
// visited once and only once. The total time complexity is then O(V+E). V is the total number of 
// vertices and E is the total number of edges. In our problem, O(V) = O(mn), O(E) = O(4V) = O(mn).
// Space O(mn)
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return 0;
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n, 0)); // memo stores the longest increasing path starting with cell(i,j)
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans = max(ans, dfs(matrix, i, j, memo));
            }
        }
        return ans;
    }
private:
    const int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m = 0, n = 0;
    
    int dfs(const vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& memo) {
        if (memo[i][j] != 0) return memo[i][j];
        for (auto d : dirs) {
            int x = i + d[0], y = j + d[1];
            if (0 <= x && x < m && 0 <= y && y < n && matrix[x][y] > matrix[i][j])
                memo[i][j] = max(memo[i][j], dfs(matrix, x, y, memo));
        }
        return ++memo[i][j]; // to include the cell itself
    }
};
