// Function time

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> functionTime(vector<string> log, string job) {
        vector<int> ans;
        vector<string> vs;
        stack<pair<string, int>> stk;
        int start = 0, end = 0;
        int pre = 0;
        int time = 0;
        bool counting = false;
        for(auto i : log) {
            vs = split(i, ',');
            if (vs[0] == job && vs[1] == "START") {
                start = stoi(vs[2]);
                counting = true;
                pre = start;
                continue;
            }
            if (!counting) continue;
            if (vs[0] == job && vs[1] == "END") {
                time += stoi(vs[2]) - pre;
                end = stoi(vs[2]);
                ans.push_back(end - start);
                ans.push_back(time);
                break;
            }
            if (vs[0] != job) {
                if (stk.empty()) {
                    time += stoi(vs[2]) - pre;
                    stk.push(make_pair(vs[0], stoi(vs[2])));
                } else {
                    if (stk.top().first == vs[0]) {
                        assert(vs[1] == "END");
                        pre = stoi(vs[2]);
                        stk.pop();
                    } else {
                        assert(vs[1] == "START");
                        stk.push(make_pair(vs[0], stoi(vs[2])));
                    }
                }
            }
        }
        return ans;
    }

private:
    vector<string> split(const string& s, char delimiter)
    {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }
};

int main() {
    vector<string> input = {"abc,START,100",
                            "def,START,150",
                            "hij,START,170",
                            "hij,END,200",
                            "def,END,220",
                            "job4,START,230",
                            "job4,END,250",
                            "abc,END,300"
                           };
    Solution s;
    vector<int> ans;
    ans = s.functionTime(input, "abc");
    cout << "inclusive time=" << ans[0] << endl;
    cout << "exclusive time=" << ans[1] << endl;
    return 0;
}