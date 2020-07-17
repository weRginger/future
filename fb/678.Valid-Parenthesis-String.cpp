// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-678-valid-parenthesis-string/
// Time O(n^3)
// Space O(n^2)
class Solution {
public:
    bool checkValidString(const string& s) {
        int l = s.length();
        m_ = vector<vector<int>>(l, vector<int>(l, -1));
        return isValid(s, 0, l - 1);
    }
private:
    vector<vector<int>> m_;
    bool isValid(const string& s, int i, int j) {
        if (i > j) return true;
        if (m_[i][j] >= 0) return m_[i][j];        
        
        if (i == j) return m_[i][j] = (s[i] == '*');
        
        if ((s[i] == '(' || s[i] == '*')
          &&(s[j] == ')' || s[j] == '*')
          && isValid(s, i + 1, j - 1))
                return m_[i][j] = 1;        
        
        for (int p = i; p < j; ++p)
            if (isValid(s, i, p) && isValid(s, p + 1, j))
                return m_[i][j] = 1;                        
        
        return m_[i][j] = 0;
    }
};

// greedy, too hard to come out on one's own
// see https://leetcode.com/problems/valid-parenthesis-string/solution/
// Time O(n)
// Space O(1)
class Solution {
public:
    bool checkValidString(string s) {
        int lo = 0, hi = 0;
        for (auto c: s) {
            lo += c == '(' ? 1 : -1;
            hi += c != ')' ? 1 : -1;
            if (hi < 0) return false;
            lo = max(lo, 0);
        }
        return lo == 0;
    }
};
