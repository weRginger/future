class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.empty()) {
            return 0;
        }
        sort(intervals.begin(), intervals.end());
        auto comp = [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
        int s = intervals.size();
        for(int i = 0; i < s; i++) {
            if (!pq.empty() && pq.top()[1] <= intervals[i][0]) {
                pq.pop();
            }
            pq.push(intervals[i]);
        }
        return pq.size();
    }
};

// Source: https://www.youtube.com/watch?v=jUpuIio_oYo
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> starts, ends;
        for (auto i : intervals) {
            starts.push_back(i[0]);
            ends.push_back(i[1]);
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
