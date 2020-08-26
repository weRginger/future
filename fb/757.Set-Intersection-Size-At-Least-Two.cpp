// Time O(nlogn)
// Space O(n)
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) {
            return 2;
        }

        sort(intervals.begin(), intervals.end(), [](const auto& l, const auto& r) {
            return l[1] < r[1];
        });

        vector<int> cur;
        int res = 0;
        for (int i = 0; i < intervals.size(); ++i) {
            if (cur.empty() || cur[1] < intervals[i][0]) {
                cur = {intervals[i][1] - 1, intervals[i][1]};
                res += 2;
            } else {
                if (cur[0] < intervals[i][0]) {
                    if (cur[1] == intervals[i][1]) {
                        cur = {intervals[i][1] - 1, intervals[i][1]};    
                    } else {
                        cur = {cur[1], intervals[i][1]};
                    }
                    res += 1;
                }
            }
        }

        return res;
    }
};
