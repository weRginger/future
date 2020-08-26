// Time O(nlogn)
// Space O(n)
// https://www.cnblogs.com/grandyang/p/8503476.html
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        vector<int> v{-1, -1};
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1] || (a[1] == b[1] && a[0] > b[0]);
        });
        for (auto &interval : intervals) {
            int len = v.size();
            if (interval[0] <= v[len - 2]) continue;
            if (interval[0] > v.back()) v.push_back(interval[1] - 1);
            v.push_back(interval[1]);
        }
        return v.size() - 2;
    }
};
