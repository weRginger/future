// Time O(n)
// Space O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numsSet(nums.begin(), nums.end());
        int longestStreak = 0;
        for(auto i : numsSet) {
            // only start searching when i is the begining (i.e. smallest)
            // of a sequence to avoid redundent searching
            if(!numsSet.count(i - 1)) {
                int currentStreak = 1;
                int curr = i + 1;
                while(numsSet.count(curr)) {
                    currentStreak++;
                    curr++;
                }
                longestStreak = max(currentStreak, longestStreak);
            }
        }
        return longestStreak;
    }
};
