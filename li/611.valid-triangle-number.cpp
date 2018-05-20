class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.empty() || nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < nums.size() - 2; i++) {
            // The following line is very important. Removed will cause error!
            // The reason is there are cases j == k,
            // if nums[i] == 0, then the while loop will break and k - j - 1 == 0
            if(nums[i] == 0) continue;
            int k = i + 2;
            for(int j = i + 1; j < nums.size() - 1; j++) {
                while(k < nums.size() && nums[i] + nums[j] > nums[k]) {
                    k++;
                }
                ans += k - j - 1;
            }
        }
        return ans;
    }
};