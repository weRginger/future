// Great question
// Time O(m*n)
// Space O(m*n)
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.empty() || rooms[0].empty()) 
            return;
        int rs = rooms.size();
        int cs = rooms[0].size();
        
        queue<pair<int, int>> q;
        for(int i = 0; i < rs; i++) {
            for(int j = 0; j < cs; j++) {
                if(rooms[i][j] == 0)
                    q.push({i, j});
            }
        }
        
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            int r = p.first;
            int c = p.second;
            for(int j = 0; j < 4; j++) {
                int row = r + dir[j][0];
                int col = c + dir[j][1];
                
                if(row < 0 || 
                   row >= rs || 
                   col < 0 || 
                   col >= cs || 
                   rooms[row][col] != INT_MAX) {
                    continue;
                }
                    
                rooms[row][col] = rooms[r][c] + 1;
                q.push({new_r, col});
            }
        }
    }
};
