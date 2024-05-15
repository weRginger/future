// Time O(n)
// Space O(1)
// ziqi's solution
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int sz = nums.size();
        for(int i = 0, zero_idx = sz; i < sz; i++) {
            if(nums[i] == 0) {
                if(zero_idx == sz) { // using sz to indicate whether we have seen 0
                    zero_idx = i;
                }
            } else {
                if(zero_idx < i) { // means we have seen 0
                    nums[zero_idx++] = nums[i];
                    nums[i] = 0;
                }
            }
        }
    }
};

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
