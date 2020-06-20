class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> rows = collectRows(grid);
        vector<int> cols = collectCols(grid);
        return minDistance1D(rows) + minDistance1D(cols);
    }
    
private:
    vector<int> collectRows(const vector<vector<int>>& grid) {
        vector<int> rows;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == 1) {
                    rows.push_back(row);
                }
            }
        }
        return rows;
    }

    vector<int> collectCols(const vector<vector<int>>& grid) {
        vector<int> cols;
        for (int col = 0; col < grid[0].size(); col++) {
            for (int row = 0; row < grid.size(); row++) {
                if (grid[row][col] == 1) {
                    cols.push_back(col);
                }
            }
        }
        return cols;
    }
    
    int minDistance1D(const vector<int>& points) {
        int distance = 0;
        int i = 0;
        int j = points.size() - 1;
        while (i < j) {
            distance += points[j] - points[i];
            i++;
            j--;
        }
        return distance;
    }
};
