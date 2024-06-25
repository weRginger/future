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
        
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            sum = sum % k;
            if(i > 0 && sum == 0){ // start from index 0 and len >= 2
                return true;
            }
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
