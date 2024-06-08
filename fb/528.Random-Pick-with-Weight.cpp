// Time O(N) for c-tor and O(logN) for pickIndex
// Space O(N)

class Solution {
private:
    vector<int> prefixSums;
    int totalSum;
public:
    Solution(vector<int>& w) {
        int prefixSum = 0;
        for(auto num : w) {
            prefixSum += num;
            prefixSums.push_back(prefixSum);
        }
        this.totalSum = prefixSum;
    }
    
    int pickIndex() {
        double target = this.totalSum * Math.random();
        int l = 0;
        int r = prefixSums.size();
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(prefixSums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};

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
