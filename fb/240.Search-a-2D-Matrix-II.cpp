// Time O(m+n)
// Space O(1)
// This would work equally well with a pointer initialized to the top-right.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size() - 1;
        int col = 0;

        while (row >= 0 && col < matrix[0].size()) {
            if (matrix[row][col] > target) {
                row--;
            } else if (matrix[row][col] < target) {
                col++;
            } else { // found it
                return true;
            }
        }

        return false;
    }
};
