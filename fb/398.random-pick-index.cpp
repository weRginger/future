// Author: Huahua
// Running time: 92 ms
class Solution {
public:
    Solution(vector<int> nums) {
        nums_ = std::move(nums);
    }

    int pick(int target) {
        int n = 0;
        int index = -1;
        for (int i = 0; i < nums_.size(); ++i) {
            if (nums_[i] != target) continue;
            ++n;
            if (rand() % n == 0) index = i;
        }
        return index;
    }
private:
    vector<int> nums_;
};

class Solution {
public:
    Solution(vector<int> nums) {
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        vector<int> arr = mp[target];
        int idx = rand() % arr.size();
        return arr[idx];
    }
private:
    unordered_map<int, vector<int>> mp;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */

