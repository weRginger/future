// Time O(n)
// Space O(n)
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        int N = s.size();
        unordered_map<char, char> um;
        for(int i = 0; i < N; i++) {
            if(!um.count(s[i]))
                um[s[i]] = t[i];
            else {
                if(um[s[i]] != t[i])
                    return false;
            }
        }
        um.clear();
        for(int i = 0; i < N; i++) {
            if(!um.count(t[i]))
                um[t[i]] = s[i];
            else {
                if(um[t[i]] != s[i])
                    return false;
            }
        }
        return true;
    }
};
