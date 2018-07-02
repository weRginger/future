/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

// Source: https://www.youtube.com/watch?v=jUpuIio_oYo
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> starts, ends;
        for (auto i : intervals) {
            starts.push_back(i.start);
            ends.push_back(i.end);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int end = 0, ans = 0;
        int s = intervals.size();
        for (int i = 0; i < s; i++) {
            if(starts[i] < ends[end]) {
                ans++;
            }
            else {
                end++;
            }
        }
        return ans;
    }
};

// Author: Ziqi
class Solution2 {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) {
            return 0;
        }
        int ans = 0;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b)
        {
            return a.start < b.start;
        });
        auto comp = [](Interval a, Interval b) {
            return a.end > b.end;
        };
        priority_queue<Interval, vector<Interval>, decltype(comp)> pq(comp);
        int s = intervals.size();
        for(int i = 0; i < s; i++) {
            while(!pq.empty() && pq.top().end <= intervals[i].start) {
                pq.pop();
            }
            pq.push(intervals[i]);
            ans = max(ans, (int)pq.size());
        }
        return ans;
    }
};