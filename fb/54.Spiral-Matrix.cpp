// Time O(mn)
// Space O(mn)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int R = matrix.size(), C = matrix[0].size();
        vector<vector<bool>> seen(R, vector<bool>(C, false));
        vector<vector<int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int r = 0, c = 0, dir = 0;
        while(ans.size() < R * C) {
            ans.push_back(matrix[r][c]);
            seen[r][c] = true;
            int cr = r + dirs[dir][0];
            int cc = c + dirs[dir][1];
            if (0 <= cr && cr < R && 0 <= cc && cc < C && !seen[cr][cc]) {
                r = cr;
                c = cc;
            } else {
                dir = (dir + 1) % 4;
                r += dirs[dir][0];
                c += dirs[dir][1];
            }
        }
        return ans;
    }
};
