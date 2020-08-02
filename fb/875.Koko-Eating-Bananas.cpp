// Time O(n*logh), where n is |piles| and h is r - l
// Space O(1)
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 1;
        int r = INT_MIN;
        for (auto p : piles) r = max(r, p);
        while (l  + 1 < r) {
            int m = (r - l) / 2 + l;
            int h = 0;
            for (auto p : piles)
                h += (p + m - 1) / m; // get ceiling
            if (h <= H)
                r = m;
            else
                l = m;
        }
        int h = 0;
        for (int p : piles)
            h += (p + l - 1) / l;
        if (h <= H)
            return l;
        return r;
    }
};
