// Time O(n)
// Space O(1)
/*
we only scan the following sequence for the next number that meet the condition.
If the next item does not meet the condition, it could be swapped with the current item.
Because if the current item is greater than the previous item, if we are looking for the
next item that is smaller than the current item, but found it is greater than current,
then the next item must also be greater than the previous item, so it is safe to swap.
If the current item is smaller than the preivous item, if we are looking for the next
item that is greater than the current item, buf found it is smaller than current,
then the next item must also be smaller than the previous item, so it is safe to swap.
*/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.empty())
            return;
        bool less = true;
        for(int i = 0; i < nums.size() - 1; i++) {
            if(less) {
                if(nums[i] > nums[i + 1]) {
                    swap(nums[i], nums[i + 1]);
                }
            } else {
                if(nums[i] < nums[i + 1]) {
                    swap(nums[i], nums[i + 1]);
                }
            }
            less = !less;
        }
    }
};
