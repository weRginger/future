// Time O(n^2)
// Space O(n)
class Solution {
public:
    bool splitArray(vector<int>& nums) {
        int S = nums.size();
        
        if (S < 7)
            return false;
        
        int sum[S];
        sum[0] = nums[0];
        for (int i = 1; i < S; i++) {
            sum[i] = sum[i - 1] + nums[i];
        }
        
        for (int j = 3; j < S - 3; j++) {
            unordered_set<int> us;
            for (int i = 1; i < j - 1; i++) {
                if (sum[i - 1] == sum[j - 1] - sum[i])
                    us.insert(sum[i - 1]);
            }
            for (int k = j + 2; k < S - 1; k++) {
                if (sum[S-1] - sum[k] == sum[k-1] - sum[j] 
                    && us.count(sum[k-1] - sum[j]))
                    
                    return true;
            }
        }
        
        return false;
    }
};
