class Solution {
public:
    int numDecodings(string s) {
        int ways_1 = 0, ways_2 = 0, ways = 0; // read as ways minus 1, ways minus 2 and ways
        if (s.empty() || s[0] == '0')
            return 0;
        ways_1 = ways_2 = ways = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '0') {
                ways = (s[i-1] == '1' || s[i-1] == '2') ? ways_2 : 0;
            } else {
                ways = (s[i-1] == '1' || (s[i-1] == '2' && s[i] <'7')) ?
                       (ways_1 + ways_2) : ways_1;
            }
            ways_2 = ways_1;
            ways_1 = ways;
        }
        return ways;
    }
};