// Time O(n)
// Space O(1)
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty()) return true;
        if(t.empty()) return false;
        for(int i = 0, j = 0; i < t.size(); i++) {
            if(t[i] == s[j]) {
                j++;
                if(j == s.size())
                    return true;
            }
        }
        return false;
    }
};
