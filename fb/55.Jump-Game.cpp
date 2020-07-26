// Author: Ziqi
// Time O(n)
// Space O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int N = nums.size() - 1;
        int maxReach = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(maxReach < i)
                return false;
            maxReach = max(maxReach, i + nums[i]);
            if(maxReach >= N)
                return true;
        }
        return true;
    }
};
