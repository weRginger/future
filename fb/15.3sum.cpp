class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> vec;
        for(int i = 0 ; i <= len-3 ; i++) {
            if(i == 0 || (i>0 && nums[i] != nums[i-1])) {
                int j = i+1;
                int k = len-1;
                while(j<k) {
                    int sum = nums[i]+nums[j]+nums[k];
                    if(sum == 0) {
                        vec.push_back(vector<int> {nums[i], nums[j], nums[k]});
                        while(j<k && (nums[j] == nums[j+1])) j++;
                        while(j<k && (nums[k] == nums[k-1])) k--;
                        j++;
                    } else if(sum < 0) {
                        j++;
                    } else {
                        k--;
                    }
                }
            }
        }
        return vec;
    }
};