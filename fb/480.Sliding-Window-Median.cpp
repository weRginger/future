// insertion sort
// Time complexity: O(k*logk +  (n – k + 1)*k)
// Space complexity: O(k)
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        if (k == 0) return ans;
        vector<int> window(nums.begin(), nums.begin() + k - 1);
        std::sort(window.begin(), window.end());
        for (int i = k - 1; i < nums.size(); ++i) {
            window.push_back(nums[i]);
            auto it = prev(window.end(), 1);
            auto const insertion_point = std::upper_bound(window.begin(), it, *it);             std::rotate(insertion_point, it, it + 1);          
            ans.push_back((static_cast<double>(window[k / 2]) + window[(k - 1) / 2]) / 2);
            window.erase(std::find(window.begin(), window.end(), nums[i - k + 1]));      
        }
        return ans;
    }
};
