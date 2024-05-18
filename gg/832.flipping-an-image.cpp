class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        if(A.empty() || A[0].empty()) return A;
        int rs = A.size();
        int cs = A[0].size();
        for(int i = 0; i < rs; i++) {
            reverse(A[i].begin(), A[i].end());
            for(int j = 0; j < cs; j++) {
                A[i][j] = A[i][j] == 0 ? 1 : 0;
            }
        }
        return A;
    }
};