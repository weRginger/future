// Time O(m*n)
// Space O(m*n)
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        m = board.size();
        n = board[0].size();
        visited.assign(m, vector<bool>(n, false));

        int x, y;
        for (int i = 0; i < click.size(); i += 2) {
            x = click[i];
            y = click[i + 1];
            dfs(board, x, y);
        }

        return board;
    }
    
private:
    vector<vector<bool>> visited;
    int m, n;
    
    const int offsetX[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
    const int offsetY[8] = {-1,  0,  1, -1, 1, -1, 0, 1};

    void dfs(vector<vector<char>>& board, int x, int y) {
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return ;
        }

        if (board[x][y] != 'E')
            return ;

        int mines = 0;

        visited[x][y] = true;

        for (int i = 0; i < 8; i++) {
            int row = x + offsetX[i];
            int col = y + offsetY[i];

            if (row < 0 || row >= m || col < 0 || col >= n)
                continue;
            if (board[row][col] == 'M')
                mines++;
        }

        if (mines > 0) {
            board[x][y] = '0' + mines;
        } else {
            board[x][y] = 'B';

            for (int i = 0; i < 8; i++) {
                int row = x + offsetX[i];
                int col = y + offsetY[i];

                if (row < 0 || row >= m || col < 0 || col >= n || visited[row][col])
                    continue;
                dfs(board, row, col);
            }
        }
    }
};
