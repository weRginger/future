// Time O(n)
// Space O(1)
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.empty()) return {};
        int S = nums.size();
        int l = 0;
        vector<string> ans;
        for(int i = 1; i < S; i++) {
            if(nums[i] != nums[i-1] + 1) {
                if(l == i - 1) {
                    ans.push_back(to_string(nums[l]));
                } else {
                    ans.push_back(to_string(nums[l]) + "->" + to_string(nums[i-1]));
                }
                l = i;
            }
        }
        
        if(l == S - 1) {
            ans.push_back(to_string(nums[l]));
        } else {
            ans.push_back(to_string(nums[l]) + "->" + to_string(nums[S-1]));
        }
        
        return ans;
    }
};
