// Time O(n)
// Space O(1)
class Solution {
public:
    int minAddToMakeValid(string S) {
        int ans = 0, bal = 0;
        for (int i = 0; i < S.length(); ++i) {
            bal += S[i] == '(' ? 1 : -1;
            // It is guaranteed bal >= -1
            if (bal == -1) {
                ans++;
                bal++;
            }
        }

        return ans + bal;
    }
};
