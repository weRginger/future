// Ziqi: this is a variation of cumulative sum problem
// Time O(n)
// Space O(n)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int diff = 0;
        unordered_map<int, int> diff_index;
        int max_length = 0;
        for (int i = 0; i < nums.size(); ++i) {
            diff = nums[i] == 0 ? diff + 1 : diff - 1;
            if (diff == 0) {
                max_length = i + 1;
            } else if (diff_index.find(diff) != diff_index.end()) {
                // if found, it means there is alerady some other subarray having the same diff that
                // further means the subarray from (diff_index[diff] + 1) to i inclusive have equal num of 0s and 1s.
                max_length = max(max_length, i - diff_index[diff]);
            } else {
                diff_index[diff] = i;
            }
        }
        return max_length;
    }
};
