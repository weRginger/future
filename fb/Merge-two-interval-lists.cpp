/*
Given A and B two interval lists, A has no overlap inside A and B has no overlap inside B.
Write the function to merge two interval lists, output the result with no overlap.
Ask for a very efficient solution

For example,
A: [1,5], [10,14], [16,18]
B: [2,6], [8,10], [11,20]

output [1,6], [8, 20]
*/
vector<pair<int, int>> mergeNonOverlappingIntervals(vector<pair<int, int>>& a, vector<pair<int, int>>& b) {
        int s = INT_MIN, e = INT_MIN, i = 0, j = 0;
        vector<pair<int,int>> res;
        while (i < a.size() || j < b.size()) {
            pair<int, int> cur;
            if (i >= a.size()) cur = b[j++];
            else if (j >= b.size()) cur = a[i++];
            else cur = a[i].first < b[j].first ? a[i++] : b[j++];
            if (cur.first > e) {
                // should not push to res if it is the first pair (s, e),
                // so here we use e > INT_MIN to check  
                if (e > INT_MIN) 
                    res.push_back(s, e);
                s = cur.first;
                e = cur.second;
            }
            else {
                e = max(cur.second, e);
            }
        }
        if (e > INT_MIN) res.push_back(s, e);
        return res;
    }
