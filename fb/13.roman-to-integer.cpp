// Time O(1), since input is less than 3999
// Space O(1)
class Solution {
public:
    int romanToInt(string s) {
        if(s.empty()) return 0;
        unordered_map<char, int> m = { {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int ans = m[s.back()];
        int size = s.size();
        for(int i = size - 2; i >= 0; i--) {
            ans += m[s[i]] >= m[s[i+1]] ? m[s[i]] : -m[s[i]];
        }
        return ans;
    }
};
