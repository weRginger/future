// Time O(n)
// Space O(n)
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        st.push(s[0]);
        for(int i = 1; i < s.size(); i++) {
            if(st.empty()) {
                st.push(s[i]);
            } else if(s[i] == st.top()) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        string ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
