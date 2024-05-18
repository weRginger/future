// Time: O(1) per move()
// Space O(n)
class TicTacToe {
private:
    // No need to use a 2D matrix to track.
    // Simply track if a direction has one player reached the board len.
    const int len;
    vector<int> rows;     // can win on a certain row
    vector<int> cols;     // can win on a certain column
    int slash = 0;        // can win on a slash / 
    int back_slash = 0;   // can win on a backslash \
    
    int hash(const int player) {
        return player == 1 ? -1 : 1; // 1-> -1, 2-> 1
    }
    
public:
    /** Initialize your data structure here. */
    TicTacToe(int n): len(n) {
        rows.resize(len, 0);
        cols.resize(len, 0);
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        // back slash
        if (row == col) {
            back_slash += hash(player);
            if (back_slash == len)
                return 2;
            else if (back_slash == -len)
                return 1;
        }
        
        // slash
        if (row == len - col - 1) {
            slash += hash(player);
            if (slash == len)
                return 2;
            else if (slash == -len)
                return 1;
        }
        
        // rows and cols
        rows[row] += hash(player);
        if (rows[row] == len)
            return 2;
        else if (rows[row] == -len)
            return 1;

        cols[col] += hash(player);
        if (cols[col] == len)
            return 2;
        else if (cols[col] == -len)
            return 1;   
        
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
