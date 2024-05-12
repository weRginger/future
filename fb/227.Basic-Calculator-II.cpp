// Author: Ziqi
// Time O(n)
// Space O(1)
class Solution {
public:
    int calculate(string s) {
        int ans = 0;
        int pre = 0;
        char lastOP = '+';
        for(int i = 0; i < s.size();) {
            if(s[i] == ' ') { // or use if(iswspace(s[i])
                i++;
            }
            else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                lastOP = s[i++];
            }
            else {
                int j = i+1;
                for(; s[j] >= '0' && s[j] <= '9'; j++) {}
                int num = stoi(s.substr(i, j - i));
                switch(lastOP) {
                    case '+':
                        ans += num;
                        pre = num;
                        break;
                    case '-':
                        ans -= num;
                        pre = -num;
                        break;
                    case '*':
                        ans = ans - pre + pre * num;
                        pre = pre * num;
                        break;
                    case '/':
                        ans = ans - pre + pre / num;
                        pre = pre / num;
                        break;
                }
                i = j;
            }
        }
        return ans;
    }
};
