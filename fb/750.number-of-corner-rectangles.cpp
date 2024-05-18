// source: https://blog.csdn.net/magicbean2/article/details/79552547
class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int ans = 0;
        for (int r1 = 0; r1 + 1 < grid.size(); ++r1) {
            for (int r2 = r1 + 1; r2 < grid.size(); ++r2) {
                int counter = 0;
                for (int c = 0; c < grid[0].size(); ++c) {
                    if (grid[r1][c] == 1 && grid[r2][c] == 1) {
                        ++counter;
                    }
                }
                ans += counter * (counter - 1) / 2;
            }
        }
        return ans;
    }
};