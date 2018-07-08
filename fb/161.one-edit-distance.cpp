class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(s == t)
            return false;
        if((int)s.length() - (int)t.length() > 1 || (int)s.length() - (int)t.length() < -1)
            return false;
        int i = 0, j = 0;
        while(i < s.length() && j < t.length()) {
            if(s[i] != t[j]) {
                if (s.substr(i+1, s.length()- (i+1)) == t.substr(j+1, t.length()- (j+1)) ||    // replace
                        s.substr(i, s.length()- (i)) == t.substr(j+1, t.length()- (j+1)) ||    // delete
                        s.substr(i+1, s.length()- (i+1)) == t.substr(j, t.length()- (j)))      // insert
                    return true;
                else
                    return false;
            }
            ++i;
            ++j;
        }
        return true;
    }
};