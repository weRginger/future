// time O(n*k)
// space O(k)
class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 1; i < n; i++) { // skip n == 1, base case
            string next = "";
            int j = 1, freq = 1;
            while(j < ans.size()) {
                if(ans[j] == ans[j-1]) {
                    freq++;
                } else {
                    next.push_back('0' + freq);
                    next.push_back(ans[j-1]);
                    freq = 1;
                }
                j++;
            }
            next.push_back('0' + freq);
            next.push_back(ans[j-1]);
            ans = next;
        }
        return ans;
    }
};
