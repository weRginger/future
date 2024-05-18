// Time O(mn)
// Space O(mn)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty()) return ans;
        int R = matrix.size(), C = matrix[0].size();
        bool seen[R][C];
        for(auto i = 0; i < R; i++)
            for(auto j = 0; j < C; j++)
                seen[i][j] = false;
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        int r = 0, c = 0, di = 0;
        for (int i = 0; i < R * C; i++) {
            ans.push_back(matrix[r][c]);
            seen[r][c] = true;
            int cr = r + dr[di];
            int cc = c + dc[di];
            if (0 <= cr && cr < R && 0 <= cc && cc < C && !seen[cr][cc]) {
                r = cr;
                c = cc;
            } else {
                di = (di + 1) % 4;
                r += dr[di];
                c += dc[di];
            }
        }
        return ans;
    }
};
