class Solution {
public:
    string countAndSay(int n) {
        if(n < 1) return string();
        string ans = "1";
        for(int i = 2; i <= n; i++) {
            string next = "";
            int j = 1, count = 1;
            for(; j < ans.size(); j++) {
                if(ans[j] == ans[j-1])
                    count++;
                else {
                    next += to_string(count) + ans[j-1];
                    count = 1;
                }
            }
            next += to_string(count) + ans[j-1];
            ans = next;
        }
        return ans;
    }
};