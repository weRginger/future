class Solution {
public:
    int totalHammingDistance(vector<int>& nums)
    {
        if (nums.empty())
            return 0;

        int ans = 0, n = nums.size();
        vector<int> cnt(32, 0);         // count of elements with a particular bit ON

        for (auto num : nums) {         // loop over every element
            int i = 0;
            while (num > 0) {           // check every bit
                cnt[i] += (num & 0x1);
                num >>= 1;
                i++;
            }
        }

        for (auto&& k : cnt) {           // loop over every bit count
            ans += k * (n - k);
        }

        return ans;
    }
};