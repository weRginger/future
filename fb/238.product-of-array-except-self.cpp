// Time O(n)
// Space O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans(size, 1);
        
        for(int i = 1; i < size; i++) {
            ans[i] = ans[i-1] * nums[i-1]; 
        }
        
        int product = nums[size-1];
        for(int i = size - 2; i >= 0; i--) {
            ans[i] *= product;
            product *= nums[i];
        }
        
        return ans;
    }
};
