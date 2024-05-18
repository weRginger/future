// Backtracking hard to estimate complexity. Details see leetcode solution page
class Solution {
private:
    // use "string& cur" for space efficiency, but have to backtrack
    void helper(int l, int r, string& cur, vector<string>& ans) {
        if(l == 0 && r == 0) {
            ans.push_back(cur);
            return;
        }
        int len = cur.size();
        if(l > 0) {
            cur += '(';
            helper(l - 1, r, cur, ans);
            cur.resize(len); // backtrack
        }
        if(l < r) {
            cur += ')';
            helper(l, r - 1, cur, ans);
            // ziqi: no need the following backtrack line since no other operators after it
            // cur.resize(len); 
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
