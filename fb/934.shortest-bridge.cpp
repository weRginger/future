// Time O(n^2)
// Space O(n^2)
class Solution {
private:
    pair<int, int> findFirstIslandCell(vector<vector<int>>& grid, int n) {
        // Find any land cell, and we treat it as a cell of island A.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int firstX = -1, firstY = -1;
        vector<int> dirs = {0, 1, 0, -1 ,0};
        
        auto p = findFirstIslandCell(grid, n);
        firstX = p.first;
        firstY = p.second;

        // bfsQueue for BFS on land cells of island A; secondBfsQueue for BFS on water cells.
        queue<vector<int>> bfsQueue;
        queue<vector<int>> secondBfsQueue;
        bfsQueue.push({firstX, firstY});
        secondBfsQueue.push({firstX, firstY});
        grid[firstX][firstY] = 2;

        // BFS for all land cells of island A and add them to secondBfsQueue.
        while (!bfsQueue.empty()) {
            auto front = bfsQueue.front();
            bfsQueue.pop();
            int x = front[0];
            int y = front[1];
            for(int i = 0; i < 4; i++) {
                int curX = x + dirs[i];
                int curY = y + dirs[i + 1];
                if (curX >= 0 && curX < n && curY >= 0 && curY < n && grid[curX][curY] == 1) {
                    bfsQueue.push({curX, curY});
                    secondBfsQueue.push({curX, curY});
                    grid[curX][curY] = 2;
                }
            }
        }

        int distance = 0;
        while (!secondBfsQueue.empty()) {
            int sz = secondBfsQueue.size();
            for(int m = 0; m < sz; m++) {
                auto front = secondBfsQueue.front();
                secondBfsQueue.pop();
                int x = front[0];
                int y = front[1];
                for(int i = 0; i < 4; i++) {
                    int curX = x + dirs[i];
                    int curY = y + dirs[i + 1];
                    if (curX >= 0 && curX < n && curY >= 0 && curY < n) {
                        if (grid[curX][curY] == 1) {
                            return distance;
                        } else if (grid[curX][curY] == 0) {
                            secondBfsQueue.push({curX, curY});
                            grid[curX][curY] = -1;
                        }
                    }
                }
            }
            distance++;
        }
        return distance;
    }
};
