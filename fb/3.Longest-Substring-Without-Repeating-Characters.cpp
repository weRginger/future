// Time O(n)
// Space O(1)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), ans = 0;
        unordered_map<char, int> um; // current index of character
        // try to extend the range [i, j]
        for (int j = 0, i = 0; j < n; j++) {
            if (um.find(s[j]) != um.end()) {
                i = max(um[s[j]], i);
            }
            ans = max(ans, j - i + 1);
            um[s[j]] = j + 1;
        }
        return ans;
    }
};
