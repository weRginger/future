// Author: Huahua https://zxi.mytechroad.com/blog/tree/leetcode-218-the-skyline-problem/
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // abs(Event.second) stores height, and + num denotes an entering point
        // and - num denotes a leaving point
        // Event.first stores either Li or Ri based on entering or leaving point
        typedef pair<int, int> Event;

        vector<Event> es;
        hs_.clear();

        for (const auto& b : buildings) {
            // note b[2] or -b[2] to separate entering and leaving points
            es.emplace_back(b[0], b[2]);
            es.emplace_back(b[1], -b[2]);
        }

        // Sort events
        // NOTE: for entering points, if Li are equal, larger height goes first
        //       for leaving points, if Ri are equal, smaller height goes first
        // This is to cover for corner cases.
        sort(es.begin(), es.end(), [](const Event& e1, const Event& e2) {
            if (e1.first == e2.first) return e1.second > e2.second;
            return e1.first < e2.first;
        });

        vector<vector<int>> ans;

        // Process all the events
        for (const auto& e: es) {
            int x = e.first;
            bool entering = e.second > 0;
            int h = abs(e.second);

            if (entering) {
                if (h > this->maxHeight())
                    ans.push_back({x, h});
                hs_.insert(h);
            } else {
                hs_.erase(hs_.equal_range(h).first);
                if (h > this->maxHeight())
                    ans.push_back({x, this->maxHeight()});
            }
        }

        return ans;
    }
private:
    int maxHeight() const {
        if (hs_.empty()) return 0;
        return *hs_.rbegin();
    }
    multiset<int> hs_;
};
