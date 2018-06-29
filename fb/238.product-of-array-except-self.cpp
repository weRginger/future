class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        if(nums.empty()) {
            return ans;
        }
        ans.resize(nums.size(), 1);
        int pro = 1;
        for(int i = 1; i < nums.size(); i++) {
            pro *= nums[i - 1];
            ans[i] = pro;
        }
        pro = 1;
        for(int i = nums.size() - 2; i >= 0 ; i--) {
            pro *= nums[i + 1];
            ans[i] *= pro;
        }
        return ans;
    }
};
