// Time O(1)
// Space O(1)
class Solution {
public:
  bool isValidSudoku(vector<vector<char> > &board) {        
    for (int i = 0; i < 9;i++) {
      unordered_set<char> r, c;
      for (int j = 0; j < 9; j++) {
        if (board[i][j] != '.' && !r.insert(board[i][j]).second) 
          return false;
        if (board[j][i] != '.' && !c.insert(board[j][i]).second)
          return false;
      }
    }
 
    for (int p = 0; p < 3; p++)
      for (int q = 0; q < 3; q++) {
        unordered_set<char> b;
        for (int i = 0; i < 3; i++)
          for (int j = 0; j < 3; j++) {
            int x = p * 3 + i;
            int y = q * 3 + j;
            if (board[y][x] != '.' && !b.insert(board[y][x]).second)
              return false;
          }
        }
    return true;
  }
};
