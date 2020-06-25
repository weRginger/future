// Time O(nlogn)
// Space O(1)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<vector<int>> res;
        for (int i = 0; i < nums.size() && nums[i] <= 0; ++i)
            if (i == 0 || nums[i - 1] != nums[i])
                twoSumII(nums, i, res);
        return res;
    }
    void twoSumII(vector<int>& nums, int i, vector<vector<int>> &res) {
        int lo = i + 1, hi = nums.size() - 1;
        while (lo < hi) {
            int sum = nums[i] + nums[lo] + nums[hi];
            if (sum < 0 || (lo > i + 1 && nums[lo] == nums[lo - 1]))
                ++lo;
            else if (sum > 0 || (hi < nums.size() - 1 && nums[hi] == nums[hi + 1]))
                --hi;
            else
                res.push_back({ nums[i], nums[lo++], nums[hi--]});
        }
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0 ; i <= len  -3 ; i++) {
            if(i == 0 || (i > 0 && nums[i] != nums[i-1])) {
                int j = i+1;
                int k = len-1;
                while(j<k) {
                    int sum = nums[i]+nums[j]+nums[k];
                    if(sum == 0) {
                        ans.push_back(vector<int> {nums[i], nums[j], nums[k]});
                        while(j < k && (nums[j] == nums[j+1])) j++;
                        while(j < k && (nums[k] == nums[k-1])) k--;
                        j++;
                    } else if(sum < 0) {
                        j++;
                    } else {
                        k--;
                    }
                }
            }
        }
        return ans;
    }
};
