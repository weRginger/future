// Time O(logn)
// Space O(1)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[mid + 1])
                r = mid;
            else
                l = mid;
        }
        if(nums[l] > nums[r]) {
            return l;
        };
        return r;
    }
};
