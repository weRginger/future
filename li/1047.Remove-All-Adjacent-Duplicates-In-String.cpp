// Time O(n)
// Space O(n)
class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> stk;
        
        for(auto c : S) {
            if(stk.empty())
                stk.push(c);
            else {
                if(stk.top() == c)
                    stk.pop();
                else
                    stk.push(c);
            }
            
        }
        string ans;
        while(!stk.empty()) {
            ans = stk.top() + ans;
            stk.pop();
        }
        
        return ans;
    }
};
