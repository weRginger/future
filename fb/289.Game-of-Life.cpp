// Time O(m*n)
// Space O(1)
// Author Ziqi
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        int dirs[8][2] = {{-1,-1},
                          {0, -1},
                          {1, -1},
                          {-1, 0},
                          {1, 0},
                          {-1, 1},
                          {0, 1},
                          {1, 1}};
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int numOnes = 0;
                for(int k = 0; k < 8; k++) {
                    int x = i + dirs[k][0];
                    int y = j + dirs[k][1];
                    if(x < 0 || x >=m || y < 0 || y >= n)
                        continue;
                    if(board[x][y] & 1)
                        numOnes++;
                }
                if(board[i][j] & 1) {
                    if(numOnes == 2  || numOnes == 3)
                        board[i][j] |= (1 << 1);
                } else {
                    if(numOnes == 3)
                        board[i][j] |= (1 << 1);
                }
            }
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] & (1 << 1))
                    board[i][j] = 1;
                else
                    board[i][j] = 0;
            }
        }
    }
};
