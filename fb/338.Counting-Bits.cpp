// Time O(n)
// Space O(1)
// Author: Ziqi
// every power of 2, the bit pattern repeast itself by diff only on the added most significant bit
// example below: the number from 4-7 differs from 0-3 only on the most significant bit
// 0 00, 0 01, 0 10, 0 11
// 1 00, 1 01, 1 10, 1 11
class Solution {
public:
    vector<int> countBits(int num) {
        if(num == 0) return {0};
        if(num == 1) return {0 , 1};
        vector<int> ans(num + 1, 0);
        ans[1] = 1;
        int t = 2;
        for(int i = 2, j = 0; i < num + 1; i++, j++) {
            if(j == t) {
                t *= 2;
                j = 0;
            }
            ans[i] = 1 + ans[j];
        }
        return ans;
    }
};
