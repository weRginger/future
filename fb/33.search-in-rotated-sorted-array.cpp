// Time O(logn)
// Space O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) {
            return -1;
        }
        int l = 0, r = nums.size() - 1;
        while(l + 1 < r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target) {
                return mid;
            }
            if(nums[mid] >= nums[l]) {
                if(target >= nums[l] && target <= nums[mid]) {
                    r = mid;
                }
                else {
                    l = mid;
                }
            }
            else {
                if(target >= nums[mid] && target <= nums[r]) {
                    l = mid;
                }
                else {
                    r = mid;
                }
            }
        }
        if(nums[l] == target) {
            return l;
        }
        if(nums[r] == target) {
            return r;
        }
        return -1;
    }
};
