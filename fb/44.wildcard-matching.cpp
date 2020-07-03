/*
有两种特殊字符, '?'代表匹配一个任意字符, 这个比较好处理. '*'匹配任意多个字符, 这个需要
考虑匹配多个字符. 因此我们可以记下最后出现'*'的位置, 这样当后面位置不匹配的时候再回到这
里将不匹配的字符用'*'来匹配. 这样最后再判断是否p指针停留的位置到最后都是*, 如果是的话则
可以匹配, 否则不可以匹配. 一个例子如: s = "aa", p = "aa****".
*/
// Time O(min(S,P)) for the best case and better than O(SlogP) for the average case
// Space O(1)
class Solution {
public:
    bool isMatch(string s, string p) {
        int preS = -1, preP = -1, i = 0, j = 0, S = s.size(), P  =p.size();
        while(i < S) {
            if(s[i] == p[j] || p[j] == '?') {
                i++;
                j++;
            }
            else if(p[j] == '*') {
                preS = i + 1;
                preP = j++;
            }
            else if(preP == -1) 
                return false;
            else {
                i = preS;
                j = preP;
            }
        }
        while(p[j] == '*') 
            j++;
        return j==P;
    }
};

// Time O(|s|*|p|)
// Space O(|s|*|p|)
class Solution {
public:
    bool isMatch(string s, string p) {
        int S = s.size(), P = p.size();
        vector<vector<bool>> dp(S + 1, vector<bool>(P + 1, false));
        dp[0][0] = true;
        for (int i = 0; i < P; i++) {
            if (p[i] == '*' && dp[0][i])
                dp[0][i + 1] = true; // empty
        }
        for (int i = 0; i < S; i++) {
            for (int j = 0; j < P; j++) {
                if (s[i] == p[j] || p[j] == '?')
                    dp[i + 1][j + 1] = dp[i][j];
                else if (p[j] == '*')
                    dp[i + 1][j + 1] = dp[i][j + 1] || dp[i + 1][j]; // multiple || empty
            }
        }
        return dp[S][P];
    }
};
