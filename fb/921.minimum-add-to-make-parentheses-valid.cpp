// Time O(n)
// Space O(1)
// ziqi's solution
class Solution {
public:
    int minAddToMakeValid(string s) {
        // track how many left or right parentheses standing alone
        // and that will be the moves needed
        int l = 0, r = 0;
        for(auto i : s) {
            if(i == '(') {
                l++;
            } else {
                if(l > 0) { // cancel out the right with the left
                    l--;
                } else {
                    r++;
                }
            }
        }
        return l + r;
    }
};
