// Time O(n)
// Space O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i = 0, startIdxOfConsecutiveZeros = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                swap(nums[startIdxOfConsecutiveZeros++], nums[i]);
            }
        }
    }
};
