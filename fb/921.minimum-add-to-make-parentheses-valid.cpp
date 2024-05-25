// Time O(n)
// Space O(1)
// ziqi's solution
class Solution {
public:
    int minAddToMakeValid(string s) {
        int l = 0, r = 0;
        for(auto i : s) {
            if(i == '(') {
                l++;
            } else {
                if(l > 0) {
                    l--;
                } else {
                    r++;
                }
            }
        }
        return l + r;
    }
};
