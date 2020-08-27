// Time O((m*n)!)
// Space O((m*n)!)
class Solution {
public:
  int slidingPuzzle(vector<vector<int>>& board) {
    constexpr int kRows = 2;
    constexpr int kCols = 3; 
    string goal;
    string start;
    for (int i = 0; i < board.size(); ++i)
      for (int j = 0; j < board[0].size(); ++j) {
        start += (board[i][j] + '0');
        goal += (i * kCols + j + 1) % (kRows * kCols) + '0'; // 12345...0
    }
    
    if (start == goal) return 0;
    
    constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    set<string> visited{start};
    int steps = 0;
    queue<string> q;
    q.push(start);
    while (!q.empty()) {
      ++steps;
      int size = q.size();
      while (size-- > 0) {
        string s = q.front();
        q.pop();
        int p = s.find('0');
        int y = p / kCols;
        int x = p % kCols;        
        for (int i = 0; i < 4; ++i) {
          int tx = x + dirs[i][0];
          int ty = y + dirs[i][1];
          if (tx < 0 || ty < 0 || tx >= kCols || ty >= kRows) continue;
          int pp = ty * kCols + tx;
          string t(s);
          swap(t[p], t[pp]);          
          if (visited.count(t)) continue;            
          if (t == goal) return steps;
          visited.insert(t);
          q.push(t);
        }
      }      
    }
    return -1;
  }
};
