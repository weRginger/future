// Time O(n)
// Space O(1)
// Author: Ziqi
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
