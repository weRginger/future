// Time O(nlogn)
// Space O(n)
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto comp = [](int& a, int& b) {
            string sa = to_string(a);
            string sb = to_string(b);
            return sa + sb > sb + sa;
        };
        sort(nums.begin(), nums.end(), comp);
        if(nums[0] == 0) return "0";
        string ans = "";
        for(auto num : nums) {
            ans += to_string(num);
        }
        return ans;
    }
};
