// Time O(n)
// Space O(n/2)
// Without line split function - much faster than below
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        if(logs.empty() || n <= 0) return vector<int> {};
        vector<int> ans(n, 0);
        stack<int> st;
        int pre = 0;
        for(auto i : logs) {
            int col1 = i.find(":");
            int col2 = i.find(":", col1 + 1);
            int id = stoi(i.substr(0, col1));
            int time = stoi(i.substr(col2 + 1));
            string state = i.substr(col1 + 1, col2 - col1 - 1);
            if(st.empty())
                st.push(id);
            else {
                if(state == "start") {
                    ans[st.top()] += time - pre;
                    st.push(id);
                    pre = time;
                }
                else {
                    st.pop();
                    ans[id] += time - pre + 1;
                    pre = time + 1;
                }
            }
        }
        return ans;
    }
};
    }
};

// With line split function
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        if(logs.empty() | n <= 0) return vector<int> {};
        vector<int> ans(n, 0);
        stack<pair<int, int>> st;
        int pre = 0;
        for(auto i : logs) {
            vector<string> vs = split(i, ':');
            if(st.empty()) {
                st.push(make_pair(stoi(vs[0]), stoi(vs[2])));
            }
            else {
                pair<int, int> p = st.top();
                if(vs[1] == "start") {
                    ans[p.first] += stoi(vs[2]) - pre;
                    st.push(make_pair(stoi(vs[0]), stoi(vs[2])));
                    pre = stoi(vs[2]);
                }
                else {
                    st.pop();
                    ans[p.first] += stoi(vs[2]) - pre + 1;
                    pre = stoi(vs[2]) + 1;
                }
            }
        }
        return ans;
    }

private:
    vector<string> split(string& input, char token) {
        vector<string> res;
        istringstream iss(input);
        string s;
        while(getline(iss, s, token)) {
            res.push_back(s);
        }
        return res;
    }
};
