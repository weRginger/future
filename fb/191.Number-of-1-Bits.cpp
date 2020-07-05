// Time O(1)
// Space O(1)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n) {
            if(n & 1) ans++;
            n = n >> 1;
        }
        return ans;
    }
};
