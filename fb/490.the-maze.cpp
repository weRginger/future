// Time O(m*n)
// Space O(m*n)
class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
        int dirs[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        queue<vector<int>> q;
        q.push(start);
        visited[start[0]][start[1]] = true;
        while(!q.empty()) {
            auto s = q.front(); 
            q.pop();
            if (s[0] == destination[0] && s[1] == destination[1])
                return true;
            for (auto dir : dirs) {
                int x = s[0] + dir[0];
                int y = s[1] + dir[1];
                // Move the ball in the chosen direction until it can.
                while (x >= 0 && 
                       y >= 0 && 
                       x < maze.size() && 
                       y < maze[0].size() && 
                       maze[x][y] == 0) {
                    x += dir[0];
                    y += dir[1];
                }
                // Revert the last move to get the cell to which the ball rolls.
                if (!visited[x - dir[0]][y - dir[1]]) {
                    q.push({x - dir[0], y - dir[1]});
                    visited[x - dir[0]][y - dir[1]] = true;
                }
            }
        }
        return false;
    }
};
