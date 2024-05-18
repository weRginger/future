// Time O(n*logn)
// Space O(1)
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        auto comp = [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];  
        };
        sort(intervals.begin(), intervals.end(), comp);
        int prev = 0, count = 0;
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[prev][1] > intervals[i][0]) {
                if(intervals[prev][1] > intervals[i][1]) {
                    prev = i;
                }
                count++;
            } else {
                prev = i;
            }
        }
        return count;
    }
};
