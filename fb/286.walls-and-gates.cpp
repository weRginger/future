// BFS start from gate 
// Time: O(mn)
// If BFS start from empty room, time O(m^2 * n^2)
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        const auto INF = 2147483647;
				
        queue<pair<int, int>> coords;
        for (int i = 0; i < rooms.size(); ++i) {
            for (int j = 0; j < rooms[i].size(); ++j) {
                if (rooms[i][j] == 0) {
                    coords.push({i, j});
                }
            }
        }

        while (!coords.empty()) {
            auto coord = coords.front();
            coords.pop();
            int row = coord.first;
            int col = coord.second;
            if (row + 1 < rooms.size() && rooms[row + 1][col] == INF) {
                rooms[row + 1][col] = rooms[row][col] + 1;
                coords.push({row + 1, col});
            }
            if (row - 1 >= 0 && rooms[row - 1][col] == INF) {
                rooms[row - 1][col] = rooms[row][col] + 1;
                coords.push({row - 1, col});
            }
            if (col + 1 < rooms[row].size() && rooms[row][col + 1] == INF) {
                rooms[row][col + 1] = rooms[row][col] + 1;
                coords.push({row, col + 1});
            }
            if (col - 1 >= 0 && rooms[row][col - 1] == INF) {
                rooms[row][col - 1] = rooms[row][col] + 1;
                coords.push({row, col - 1});
            }
        }
    }
};