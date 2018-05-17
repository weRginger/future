class Solution {
public:
    bool isMatch(string s, string p) {
        /*
        s:text as the row
        p:pattern as the col
        build a dp table that store all the boolean values
        three cases we should consider:
        case 1: dptable[i-1][j-1]  if (p[j-1] == '.' || p[j-1] == s[i-1])
        case 2:  if (p[j-1] == '*')
        subcase 1: if zero occurance like  xa* x dptable[i][j] = dptable[i][j-2];
        subcase 2: if (p[j-2] == '.' || p[j-2] == s[i-1]) then dptable[i][j]= dptable[i][j]|dptable[i-1][j];
        case 3: dptable[i][j]=false;
        */
        int row =  s.length() +1;
        int col =  p.length() +1;

        vector<vector<bool>> dptable(row, vector<bool>(col, false));

        dptable[0][0] = true;

        // deal with pattern like a* or a*b*...
        for (int i = 1 ; i < col; i++) {
            if (p[i-1] == '*') {
                dptable[0][i] = dptable[0][i-2];
            }
        }
        for (int i = 1 ; i< row ; i++) {
            for (int j =1; j< col; j++) {
                if (p[j-1] == '.' || p[j-1] == s[i-1]) {
                    dptable[i][j] = dptable[i-1][j-1];
                }
                else if (p[j-1] == '*') {
                    dptable[i][j] = dptable[i][j-2];
                    if (p[j-2] == '.' || p[j-2] == s[i-1]) {
                        dptable[i][j] = dptable[i][j] || dptable[i-1][j];
                    }
                }
            }
        }

        return dptable[s.length()][p.length()];

    }
};
