// Time O(n(logn))
// Space O(1)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(intervals.empty()) return ans;
        sort(intervals.begin(), intervals.end());
        vector<int> curr = intervals[0];
        for(int i = 1; i < intervals.size(); i++) {
            if(curr[1] < intervals[i][0]) {
                ans.push_back(curr);
                curr = intervals[i];
            }
            else {
                curr[1] = max(curr[1], intervals[i][1]);
            }
        }
        ans.push_back(curr);
        return ans;
    }
};
