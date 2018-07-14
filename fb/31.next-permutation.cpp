class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.empty()) return;
        for(int i = nums.size() - 1; i > 0; i--) {
            if(nums[i] > nums[i-1]) {
                for(int j = nums.size() - 1; j > i - 1; j--) {
                    if(nums[j] > nums[i - 1]) {
                        swap(nums[i - 1], nums[j]);
                        reverse(nums, i);
                        return;
                    }
                }
            }
        }
        reverse(nums, 0);
    }

    void reverse(vector<int>& nums, int start) {
        int end = nums.size() - 1;
        while(start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
};
