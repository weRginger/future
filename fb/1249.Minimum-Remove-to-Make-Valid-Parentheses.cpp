// Time O(n) two-pass
// Space O(1) since modified input s
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int l = 0;
        int r = 0;
        int S = s.size();
        for(int i = 0; i < S; i++) {
            if(s[i] == '(') {
                l++;
            }
            else if(s[i] == ')') {
                if(l > 0) {
                    l--;
                } else {
                    s[i] = '#'; // mark to delete 
                }
            }
        }
        
        for(int i = S - 1; i >= 0; i--) {
            if(s[i] == '#') 
                s.erase(s.begin() + i);
            else if(s[i] == ')') {
                r++;
            }
            else if(s[i] == '(') {
                if(r > 0) {
                    r--;
                } else {
                    s.erase(s.begin() + i);
                }
            }
        }
        return s;
    }
};
