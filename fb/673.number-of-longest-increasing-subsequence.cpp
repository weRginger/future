// Author: Zhonghua Xi (huahua)
// Running time: 33 ms
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> c(n, 1);
        vector<int> l(n, 1);

        for (int i = 1; i < n; ++i)
            for(int j = 0; j < i; ++j)
                if (nums[i] > nums[j]) {
                    if (l[j] + 1 > l[i]) {
                        l[i] = l[j] + 1;
                        c[i] = c[j];
                    } else if (l[j] + 1 == l[i]) {
                        c[i] += c[j];
                    }
                }

        int max_len = *max_element(l.begin(), l.end());

        int ans = 0;
        for (int i = 0; i < n; ++i)
            if (l[i] == max_len)
                ans += c[i];

        return ans;
    }
};