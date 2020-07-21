// Time O(|nums|)
// Space O(min(|nums|, k))
/**
 * a % k = x
 * b % k = x
 * (a - b) % k = x - x = 0
 * here a - b = the sum between i and j
 */
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;
        
        // key is sum % k, value is the corresponding index
        unordered_map<int, int> um;
        um[0] = -1; // in case the satisfying sequence starting from index 0
        
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(k != 0)
                sum = sum % k;
            if(um.count(sum)) {
                if(i - um[sum] >= 2) // Q askes sequence len >= 2
                    return true;
            } else {
                um[sum] = i;
            }
        }
        
        return false;
    }
};
