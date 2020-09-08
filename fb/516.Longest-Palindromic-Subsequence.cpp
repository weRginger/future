// Time O(n^2)
// Space O(n^2)
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int S = s.size();
        return helper(s, 0, S - 1);
    }
    
private:
    unordered_map<int, unordered_map<int, int>> memo;
    
    int helper(const string& s, int l, int r) {
        if(l > r) return 0;
        if(l == r) return 1;
        if(memo.count(l) && memo[l].count(r)) {
            return memo[l][r];
        }
        int ans = INT_MIN;
        if(s[l] == s[r]) {
            ans = 2 + helper(s, l+1, r-1);
        } else {
            ans = max(helper(s, l, r-1), helper(s, l+1, r));
        }
        return memo[l][r] = ans;
    }
};
