// Time O(N) for c-tor and O(logN) for pickIndex
// Space O(N)
class Solution {
    vector<int> prefixSums;

public:
    Solution(vector<int> &w) {
        for (auto n : w)
            prefixSums.push_back(n + (prefixSums.empty() ? 
                0 : prefixSums.back()));
    }
    int pickIndex() {
        float target =  rand() % prefixSums.back();
        return upper_bound(begin(prefixSums), end(prefixSums), target) - begin(prefixSums);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
