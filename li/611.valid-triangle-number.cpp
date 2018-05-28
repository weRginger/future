// time: O(n^2)
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.empty() || nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < nums.size() - 2; i++) {
            // The following line is very important. Removed will cause error!
            // The reason is if nums[i] == 0 and j == k,
            // then the while loop will break (nums[i] + nums[j] == nums[k]),
            // which leads to k - j - 1 == -1 --> ERROR!
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