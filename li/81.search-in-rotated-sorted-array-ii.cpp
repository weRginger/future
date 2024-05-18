class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) {
            return false;
        }
        int l = 0, r = nums.size() - 1;
        while(l + 1 < r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target) {
                return true;
            }
            if(nums[mid] == nums[l] && nums[mid] == nums[r]) {
                l++;
                r--;
            }
            // Note: must use >=! Error if use > only
            else if(nums[mid] >= nums[l]) {
                if(target >= nums[l] && target < nums[mid]) {
                    r = mid;
                }
                else {
                    l = mid;
                }
            }
            else {
                if(target > nums[mid] && target <= nums[r]) {
                    l = mid;
                }
                else {
                    r = mid;
                }
            }
        }
        if(nums[l] == target) {
            return true;
        }
        if(nums[r] == target) {
            return true;
        }
        return false;
    }
};
