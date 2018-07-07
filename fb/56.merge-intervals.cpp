/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        if(intervals.empty()) return ans;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {
            return a.start < b.start;
        });
        Interval curr = intervals[0];
        for(int i = 1; i < intervals.size(); i++) {
            if(curr.end < intervals[i].start) {
                ans.push_back(curr);
                curr = intervals[i];
            }
            else {
                curr.end = max(curr.end, intervals[i].end);
            }
        }
        ans.push_back(curr);
        return ans;
    }
};
