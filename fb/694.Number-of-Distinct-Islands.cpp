// Time O(R*C)
// Space O(R*C)
class Solution {
private:
    void dfs(vector<vector<int>>& grid,
                              int i, int j, int row, int col,
                              string& coordinateHash) {
        if(i >= 0 && i < grid.size() && j >= 0 && j < grid[i].size() && grid[i][j] == 1) {
            // Mark as visited
            grid[i][j] = 0; 
            
            // Translate position to top left of grid and save coordinates as a string
            coordinateHash += to_string(i - row) + "_" + to_string(j - col);
            
            // Find left nodes
            dfs(grid, i - 1, j, row, col, coordinateHash);
            // Find right nodes
            dfs(grid, i + 1, j, row, col, coordinateHash);
            // Find bottom nodes
            dfs(grid, i, j - 1, row, col, coordinateHash);
            // Find top nodes
            dfs(grid, i, j + 1, row, col, coordinateHash); 

        }
    }
    
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        if (grid.empty() || grid.size() == 0) return 0;
        
        // Sets only keep unique data
        unordered_set<string> us;
        
        for(int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    // Second set of i, j will be used to translate coordinates to top left of grid
                    string coordinateHash;
                    dfs(grid, i, j, i, j, coordinateHash);
                    us.insert(coordinateHash);
                }
            }
        }
        
        // Will only contain coordinates of unique islands
        return us.size();
    }
};
