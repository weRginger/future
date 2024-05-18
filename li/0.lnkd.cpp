// Function time

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stack>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<string> lnkd(string num, int target) {
        vector<string> ans;
        if(num.empty()) {
            return ans;
        }
        helper(num, target, "", 0, 0, 0, ans);
        return ans;
    }

private:
    void helper(string num, int target, string cur, int pos, double eval, double last, vector<string>& ans) {
        int len = num.size();
        if(pos == len) {
            if(eval == target) {
                ans.push_back(cur);
            }
            return;
        }
        for(int i = pos; i < len; i++) {
            if(num[pos] == '0' && i != pos) break; // only allow 0 but not "03" or "026"
            string prefix = num.substr(pos, i + 1 - pos);
            long n = stoi(prefix);
            if(pos == 0) {
                helper(num, target, cur+prefix, i+1, n, n, ans); // special case for first digit
            }
            else {
                helper(num, target, cur+"+"+prefix, i+1, eval+n, n, ans);
                helper(num, target, cur+"-"+prefix, i+1, eval-n, -n, ans);
                helper(num, target, cur+"*"+prefix, i+1, eval-last+last*n, last*n, ans);
                if(n != 0) helper(num, target, cur+"/"+prefix, i+1, eval-last+last/n, last/n, ans);
            }
        }
    }
};

int main() {
    Solution s;
    vector<string> ans = s.lnkd("2011051945", 196);
    for(auto i : ans) cout << i << endl;
    cout << "total = " << ans.size() << endl;
    return 0;
}