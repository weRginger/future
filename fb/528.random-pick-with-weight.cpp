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
        totalSum = prefixSum;
    }
    
    int pickIndex() {
        // generate a random number in the range of [0, 1]
        float randNum = (float) rand() / RAND_MAX;
        float target =  randNum * totalSum;
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

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
