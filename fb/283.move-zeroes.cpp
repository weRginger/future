class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
            if (nums[cur] != 0) {
                swap(nums[lastNonZeroFoundAt++], nums[cur]);
            }
        }
    }

    void moveZeroes2(vector<int>& nums) {
        if(nums.empty()) return;
        int size = nums.size();
        int zero = -1;
        for(int i = 0; i < size; i++) {
            if(nums[i] == 0) {
                if(zero == -1) {
                    zero = i;
                }
            }
            else if(zero != -1) {
                swap(nums[zero], nums[i]);
                zero++;
            }
        }
    }
};