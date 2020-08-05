// Time O(N)
// Space O(1)
// general knight solution
class Solution {
public:
  int knightDialer(int N) {
    constexpr int kMod = 1e9 + 7;
    int dirs[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
    vector<vector<int>> dp(4, vector<int>(3, 1));
    dp[3][0] = dp[3][2] = 0;    
    for (int k = 1; k < N; ++k) {
      // creating a tmp instead of modifying on dp,
      // since each dp value needs to be used multiple times
      vector<vector<int>> tmp(4, vector<int>(3));
      for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 3; ++j) {
          if (i == 3 && j != 1) continue;
          for (int d = 0; d < 8; ++d) {           
            int tx = j + dirs[d][0];
            int ty = i + dirs[d][1];
            if (tx < 0 || ty < 0 || tx >= 3 || ty >= 4) continue;
            tmp[i][j] = (tmp[i][j] + dp[ty][tx]) % kMod;
          }          
        }
      dp.swap(tmp);
    }
    int ans = 0;
    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < 3; ++j)
        ans = (ans + dp[i][j]) % kMod;
    return ans;
  }
};

// Time O(N)
// Space O(1)
// specific to phone pad knight solution 
class Solution {
public:
  int knightDialer(int N) {
    constexpr int kMod = 1e9 + 7;
    vector<vector<int>> moves{{4,6},{8,6},{7,9},{4,8},{3,9,0},{},{1,7,0},{2,6},{1,3},{2,4}};
    vector<int> dp(10, 1);
    for (int k = 1; k < N; ++k) {
      vector<int> tmp(10);
      for (int i = 0; i < 10; ++i)
        for (int nxt : moves[i])
          tmp[nxt] = (tmp[nxt] + dp[i]) % kMod;        
      dp.swap(tmp);
    }
    int ans = 0;
    for (int i = 0; i < 10; ++i)
      ans = (ans + dp[i]) % kMod;
    return ans;
  }
};
