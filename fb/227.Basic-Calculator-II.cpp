// Time O(n)
// Space O(1)
// Author: Ziqi new
class Solution {
public:
    int calculate(string s) {
        s.push_back('+'); // add an op in the end to force calculation of the last number
        long ans = 0;
        long pre = 0;
        long cur = 0;
        char sign = '+';
        for(auto c : s) {
            if(c == ' ') continue;
            if(c >= '0' && c <= '9') {
                cur = 10 * cur + c - '0';
            } else {
                switch (sign) {
                    case '+':
                        ans += cur;
                        pre = cur;
                        break;
                    case '-':
                        ans -= cur;
                        pre = -cur;
                        break;
                    case '*':
                        ans -= pre;
                        pre = pre * cur;
                        ans += pre;
                        break;
                    case '/':
                        ans -= pre;
                        pre = pre / cur;
                        ans += pre;
                        break;
                }
                cur = 0;
                sign = c; 
            }
        }
        return ans;
    }
};

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
                lastOP = s[i];
                i++;
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
