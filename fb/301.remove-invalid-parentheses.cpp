// 背下来吧。。。
// Source: http://zxi.mytechroad.com/blog/searching/leetcode-301-remove-invalid-parentheses/
// Time: O(2^(l+r))
// Space: O(n^2)
// Runtime: 3 ms
class Solution {
public:
    vector<string> removeInvalidParentheses(const string& s) {
        int l = 0;
        int r = 0;

        for (const char ch : s) {
            l += (ch == '(');
            if (l == 0)
                r += (ch == ')');
            else
                l -= (ch == ')');
        }

        vector<string> ans;
        dfs(s, 0, l, r, ans);
        return ans;
    }
private:
    bool isValid(const string& s) {
        int count = 0;
        for (const char ch : s) {
            if (ch == '(') ++count;
            if (ch == ')') --count;
            if (count < 0) return false;
        }
        return count == 0;
    }

    // l/r: number of left/right parentheses to remove.
    void dfs(const string& s, int start, int l, int r, vector<string>& ans) {
        // Nothing to remove.
        if (l == 0 && r == 0) {
            if (isValid(s)) ans.push_back(s);
            return;
        }

        for (int i = start; i < s.length(); ++i) {
            // We only remove the first parenthes if there are consecutive ones to avoid duplications.
            if (i != start && s[i] == s[i - 1]) continue;

            if (s[i] == '(' || s[i] == ')') {
                string curr = s;
                curr.erase(i, 1);
                if (r > 0 && s[i] == ')')
                    dfs(curr, i, l, r - 1, ans);
                else if (l > 0 && s[i] == '(')
                    dfs(curr, i, l - 1, r, ans);
            }
        }
    }
};
