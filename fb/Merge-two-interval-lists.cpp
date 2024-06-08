vector<pair<int, int>> mergeNonOverlappingIntervals(vector<pair<int, int>>& a, vector<pair<int, int>>& b) {
        int s = INT_MIN, e = INT_MIN, i = 0, j = 0;
        vector<pair<int,int>> res;
        while (i < a.size() || j < b.size()) {
            pair<int, int> cur;
            if (i >= a.size()) cur = b[j++];
            else if (j >= b.size()) cur = a[i++];
            else cur = a[i].first < b[j].first ? a[i++] : b[j++];
            if (cur.first > e) {
                if (e > INT_MIN)
                    res.push_back(s, e);
                s = cur.first;
                e = cur.second;
            }
            else {
                e = max(cur.second, e);
            }
        }
        if (e > INT_MIN) res.emplace_back(s, e);
        return res;
    }
