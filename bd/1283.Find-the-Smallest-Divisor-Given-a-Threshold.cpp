class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        if (!n) return 0;
        
        int mx = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
            mx = max(mx, nums[i]);
        
        int l = 1, r = mx;
        int sum = 0;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            sum = 0;
            for (int i = 0; i < nums.size(); i++)
                sum += nums[i] % m == 0 ? nums[i] / m : nums[i] / m + 1;
            if (sum <= threshold)
                r = m;
            else
                l = m;
        }
        
        // Since we are using (l + 1 < r) as binary search terminal condition,
        // we need to verify whether l or r is the answer.
        // As this Q is asking for the smallest int, we need to try l before r.
        sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i] % l == 0 ? nums[i] / l : nums[i] /l + 1;
        if(sum <= threshold)
            return l;
        return r;
    }
};
