// Time O(log26(n))
// Space O(1)
class Solution {
public:
    string convertToTitle(int n) {
        string str = "";
        while(n) {
            str = char((n - 1) % 26 + 'A') + str;
            n = (n  - 1) / 26;
        }
        return str;
    }
};
