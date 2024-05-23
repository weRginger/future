// Time O(nlogn)
// Space O(n)
// Author: Ziqi
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.empty()) {
            return 0;
        }
        int ans = 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b)
        {
            return a[0] < b[0];
        });
        auto comp = [](vector<int> a, vector<int> b) {
            return a[1] > b[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
        int s = intervals.size();
        for(int i = 0; i < s; i++) {
            while(!pq.empty() && pq.top()[1] <= intervals[i][0]) {
                pq.pop();
            }
            pq.push(intervals[i]);
            ans = max(ans, (int)pq.size());
        }
        return ans;
    }
};
