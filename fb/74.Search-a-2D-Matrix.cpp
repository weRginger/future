// Time O(m*n)
// Space O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int l = 0;
        int r = matrix.size() * matrix[0].size() - 1;
        const int cols = matrix[0].size();
        while (l + 1 < r) {
            const int m = l + (r - l) / 2;
            if (matrix[m / cols][m % cols] == target) {
                return true;
            } else if (matrix[m / cols][m % cols] > target) {
                r = m;
            } else {
                l = m;
            }
        }
        if((matrix[l / cols][l % cols] == target) ||
           (matrix[r / cols][r % cols] == target))
            return true;
        return false;
    }
};
