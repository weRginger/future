// Time O(logn)
// Space O(1)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        // Note while condition is l "<" r to make sure nums[mid + 1] within bound.
        // If using l "<=" r, then nums[mid + 1] could be out of bound.
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[mid + 1])
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
