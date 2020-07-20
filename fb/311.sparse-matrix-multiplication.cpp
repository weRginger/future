// Time O(n^3)
// Space O(1)
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size(), n = A[0].size(), p = B[0].size();
        vector<vector<int>> ans(m, vector<int>(p, 0));
        for(int i = 0; i < m; i++)
        {
            for(int k = 0; k < n; k++)
            {
                if(A[i][k] == 0) continue;
                for(int j = 0; j < p; j++) ans[i][j] += A[i][k] * B[k][j];
            }
        }
        return ans;
    }
};
