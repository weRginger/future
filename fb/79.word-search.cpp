// Time O(N*(4^L), where N is the number of cells in the board and L is the length of the word to be matched
// Space O(L), since at most L recursions
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i != board.size(); ++i)
            for (int j = 0; j != board[i].size(); ++j)
                if(existCore(board, i, j, word, 0)) 
                    return true;
        return false;
    }
private:
    bool existCore(vector<vector<char>>& board, int i, int j, const string &word, int pos) {
        if (pos == word.size()) 
            return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || word[pos] != board[i][j])
            return false;
        char ch = board[i][j];
        board[i][j]='*';
        if (existCore(board, i, j-1, word, pos + 1) ||
            existCore(board, i, j+1, word, pos + 1) ||
            existCore(board, i-1, j, word, pos + 1) ||
            existCore(board, i+1, j, word, pos + 1))
            return true;
        
        board[i][j] = ch; // backtracking
        return false;
    }
};
