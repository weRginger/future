class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int> num_set(nums.begin(), nums.end());
        int ans = 0;
        for(int num : num_set) {
            if(!num_set.count(num-1)) {
                int currentStreak = 1;
                while (num_set.count(++num)) {
                    currentStreak += 1;
                }
                ans = max(ans, currentStreak);
            }
        }
        return ans;
    }
};

// Author: Ziqi
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for(auto i : nums) {
            int local = 1;
            int tmp = i;
            while(!s.empty() && s.count(--tmp)) {
                local++;
                s.erase(tmp);
            }
            tmp = i;
            while(!s.empty() && s.count(++tmp)) {
                local++;
                s.erase(tmp);
            }
            s.erase(i);
            ans = max(ans, local);
            if(s.empty())
                break;
        }
        return ans;
    }
};