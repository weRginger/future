// Time O(1)
// Space O(1)
class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        double eps = 0.001;
        vector<char> ops{'+', '-', '*', '/'};
        vector<double> arr(nums.begin(), nums.end());
        return helper(arr, ops, eps);
    }
    bool helper(vector<double>& nums, vector<char>& ops, double eps) {
        if (nums.size() == 1) return abs(nums[0] - 24) < eps;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i == j) continue;
                vector<double> t;
                for (int k = 0; k < nums.size(); ++k) {
                    if (k != i && k != j) t.push_back(nums[k]);
                }
                for (char op : ops) {
                    if ((op == '+' || op == '*') && i > j) continue;
                    if (op == '/' && nums[j] < eps) continue;
                    switch(op) {
                        case '+': t.push_back(nums[i] + nums[j]); break;
                        case '-': t.push_back(nums[i] - nums[j]); break;
                        case '*': t.push_back(nums[i] * nums[j]); break;
                        case '/': t.push_back(nums[i] / nums[j]); break;
                    }
                    if (helper(t, ops, eps)) return true;
                    t.pop_back();
                }
            }
        }
        return false;
    }
};
