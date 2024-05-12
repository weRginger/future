// time O(n). n is the number of integers in the grid.
// space O(sqrt(n))
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        queue<pair<int, int>> queue;
        queue.push({0, 0});
        vector<int> ans;
        
        while (!queue.empty()) {
            auto [row, col] = queue.front();
            queue.pop();
            ans.push_back(nums[row][col]);
            
            if (col == 0 && row + 1 < nums.size()) {
                queue.push({row + 1, col});
            }
            
            if (col + 1 < nums[row].size()) {
                queue.push({row, col + 1});
            }
        }
        
        return ans;
    }
};

// time O(n). n is the number of integers in the grid.
// space O(n)
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < nums[i].size(); j++) {
                mp[i+j].push_back(nums[i][j]);
            }
        }
        int i = 0;
        vector<int> ans;
        while(mp.count(i)) {
            for(int j = mp[i].size() - 1; j > -1; j--) {
                ans.push_back(mp[i][j]);
            }
            i++;
        }
        return ans;
    }
};
