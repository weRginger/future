// Time O(R*C)
// Space O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool isCol = false; // whether first col contains 0
        bool isRow = false; // whether first row contains 0
        int R = matrix.size();
        int C = matrix[0].size();

        for (int i = 0; i < R; i++) {
            if (matrix[i][0] == 0) {
                isCol = true;
            }
        }
        
        for (int i = 0; i < C; i++) {
            if (matrix[0][i] == 0) {
                isRow = true;
            }
        }

        // use first row and col to store rows and cols containing 0s
        for (int i = 1; i < R; i++) {
            for (int j = 1; j < C; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // mark them with 0
        for (int i = 1; i < R; i++) {
            for (int j = 1; j < C; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if(isRow) {
            for(int j = 0; j < C; j++) {
                matrix[0][j] = 0;
            }
        }

        if(isCol) {
            for(int i = 0; i < R; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
