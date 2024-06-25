// Time O(n)
// Space O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i = 0, startIdxOfConsecutiveZeros = 0; i < nums.size(); i++) {
            // if currnet value is not 0, just swap with itself and both startIdxOfConsecutiveZeros and i advance to the next element. 
            // NOTE: due to startIdxOfConsecutiveZeros++, it will point to the next unexamined element after this iteration
            // then, if the next element (or more future ones) is 0, startIdxOfConsecutiveZeros will stay there
            // finally, when meet another none-0, it will be swapped with startIdxOfConsecutiveZeros, which points to a 0
            if(nums[i] != 0) {
                swap(nums[startIdxOfConsecutiveZeros++], nums[i]);
            }
        }
    }
};
