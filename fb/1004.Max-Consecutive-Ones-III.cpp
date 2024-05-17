// Time O(n)
// Space O(1)
// amazing elegant solution
// details: https://leetcode.com/problems/max-consecutive-ones-iii/solution/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right;
        for (right = 0; right < nums.size(); right++) {
            // If we included a zero in the window we reduce the value of k.
            // Since k is the maximum zeros allowed in a window.
            if (nums[right] == 0) k--;
            // A negative K denotes we have consumed all allowed flips and window has
            // more than allowed zeros, thus increment left pointer by 1 to keep the window size same.
            if (k < 0) {
                // If the left element to be thrown out is zero we increase k.
                if (nums[left] == 0) k++;
                left++;
            }
        }
        return right - left;
    }
};
