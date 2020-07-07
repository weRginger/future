// Backtracking hard to estimate complexity. Details see leetcode solution page
class Solution {
private:
    void helper(int l, int r, string& cur, vector<string>& ans) {
        if(l == 0 && r == 0) {
            ans.push_back(cur);
            return;
        }
        int len = cur.size();
        if(l > 0) {
            cur += '(';
            helper(l - 1, r, cur, ans);
            cur.resize(len);
        }
        if(l < r) {
            cur += ')';
            helper(l, r - 1, cur, ans);
            cur.resize(len);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur = "";
        helper(n, n, cur, ans);
        return ans;
    }
};
