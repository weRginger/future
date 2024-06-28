// Time O(n)
// Space O(n)
// author ziqi
// note: using vector as stack to avoid the reverse in the end
class Solution {
public:
    string removeDuplicates(string s) {
        vector<char> st;
        st.push_back(s[0]);
        for(int i = 1; i < s.size(); i++) {
            if(st.empty()) {
                st.push_back(s[i]);
            } else if(s[i] == st.back()) {
                st.pop_back();
            } else {
                st.push_back(s[i]);
            }
        }
        string ans;
        for(auto c : st) {
            ans.push_back(c);
        }
        return ans;
    }
};

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
