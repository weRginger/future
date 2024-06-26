// Time O(n)
// Space O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        int counter[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            counter[s[i] - 'a']++;
            counter[t[i] - 'a']--;
        }
        for (auto count : counter) {
            if (count != 0) {
                return false;
            }
        }
        return true;
    }
};
