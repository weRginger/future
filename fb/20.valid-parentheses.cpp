// Time O(n)
// Space O(n)
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto c : s) {
            if(c == '(' || c == '{' || c == '[')
                stk.push(c);
            else {
                if(stk.empty()) return false;
                if(c == ')') {
                    char t = stk.top();
                    stk.pop();
                    if(t != '(') return false;
                }
                else if(c == ']') {
                    char t = stk.top();
                    stk.pop();
                    if(t != '[') return false;
                }
                else {
                    char t = stk.top();
                    stk.pop();
                    if(t != '{') return false;
                }
            }
        }
        return stk.empty();
    }
};
