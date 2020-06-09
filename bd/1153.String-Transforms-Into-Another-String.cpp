class Solution {
public:
    bool canConvert(string str1, string str2) {
        if(str1.length() != str2.length()) return false;
        if(str1 == str2) return true;
        unordered_map<char, char> m;
        for(int i = 0; i < str1.length(); i++) {
            if(m.find(str1[i]) == m.end()) {
                m[str1[i]] = str2[i];
            } else {
                if(m[str1[i]] != str2[i]) {
                    return false;
                }
            }
        }
        return set(str2.begin(), str2.end()).size() < 26;
    }
};
