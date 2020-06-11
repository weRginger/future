class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = nums.size() - 1;
        if(nums[0] < nums[s]) return nums[0];
        
        int l = 0, r = s;
        while(l + 1 < r) {
            int mid = l + (r - l) / 2;
            if((mid - 1 >= 0) && (nums[mid] < nums[mid - 1])) return nums[mid];
            if((mid + 1 < s) && (nums[mid] > nums[mid + 1])) return nums[mid + 1];
            if(nums[mid] >= nums[l]) {
                l = mid;
            } else {
                r = mid;
            }
        }
        if((l - 1 >= 0) && (nums[l] < nums[l - 1])) return nums[l];
        if((l + 1 < s) && (nums[l] > nums[l + 1])) return nums[l + 1];
        return nums[r];
    }
};
