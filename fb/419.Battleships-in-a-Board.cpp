// Time O(mn)
// Space O(1)
// Author: Ziqi
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int rsize = board.size();
        int csize = board[0].size();
        int ans = 0;
        for(int i = 0; i < rsize; i++) {
            for(int j = 0; j < csize; j++) {
                if(board[i][j] == 'X') {
                    if((i + 1 < rsize && board[i+1][j] == 'X') ||
                        (j+1 < csize && board[i][j+1] == 'X'))
                        continue;
                    ans++;       
                }
            }
        }
        return ans;
    }
};
