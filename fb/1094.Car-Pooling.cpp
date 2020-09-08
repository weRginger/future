// Time O(nlogn)
// Space O(n)
// Ziqi: very similar to LC 253. Meeting Rooms II
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        if(trips.empty()) return true;
        
        vector<pair<int, int>> in, out;
        for(auto trip : trips) {
            in.push_back({trip[1], trip[0]});
            out.push_back({trip[2], trip[0]});             
        }
        
        sort(in.begin(), in.end());
        sort(out.begin(), out.end());
        
        int curr = 0;
        int S = trips.size();
        for(int i = 0, j = 0; i < S; i++) {
            curr += in[i].second;
            // NOTE: need to subtract all out passengers before picking up new ones
            // So, we MUST use "while" instead of "if"
            while(out[j].first <= in[i].first) {
                curr -= out[j++].second;
            }
            if(curr > capacity)
                return false;
        }
        return true;
    }
};
