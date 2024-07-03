// Time O(n*(4^n))
// Space O(n)
class Solution {
public:
  vector<string> addOperators(string num, int target) {
    vector<string> ans;
    // tracking back "exp" is the key to pass TLE
    string exp = "";
    dfs(num, target, 0, exp, 0, 0, ans);
    return ans;
  }
private:
  void dfs(const string& num, const int target,  // input
           int pos, string& exp, long prev, long curr, // state
           vector<string>& ans) {  // output
    if (pos == num.length()) {
      if (curr == target) ans.push_back(exp);
      return;
    }
    
    for (int l = 1; l <= num.size() - pos; ++l) {
      string t = num.substr(pos, l);    
      if (t[0] == '0' && t.length() > 1) break; // 0X...
      long n = std::stol(t);
      if (n > INT_MAX) break;
      if (pos == 0) { // first number, no operations could do yet
        dfs(num, target, l, t, n, n, ans);
        continue;
      }
      int len = exp.size();
      exp += '+' + t;
      dfs(num, target, pos + l, exp, n, curr + n, ans);
      exp.resize(len);
      exp += '-' + t;
      dfs(num, target, pos + l, exp, -n, curr - n, ans);
      exp.resize(len);
      exp += '*' + t;
      dfs(num, target, pos + l, exp, prev * n, curr - prev + prev * n, ans); // similar to 227. Basic Calculator II
      exp.resize(len);
      /*
      Following code will cause TLE since each recursion creats a copy of exp
      dfs(num, target, pos + l, exp + '+' + t, n, curr + n, ans);
      dfs(num, target, pos + l, exp + '-' + t, -n, curr - n, ans);
      dfs(num, target, pos + l, exp + '*' + t, prev * n, curr - prev + prev * n, ans);
      */
    }    
  }
};
