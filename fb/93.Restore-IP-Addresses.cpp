// Time: 3*3*3 since each of the 3 dots can be placed only after 1st char, 2nd char and 3rd char
// Space: 19. See LC solution figure for this number. https://leetcode.com/problems/restore-ip-addresses/solution/
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        dfs(s, 0, "", res);
        return res;
    }
private:
    void dfs(string s, int n, string out, vector<string>& res) {
        if (n == 4) {
            if (s.empty()) res.push_back(out);
        } else {
            for (int k = 1; k < 4; ++k) {
                if (s.size() < k) break;
                int val = stoi(s.substr(0, k));
                // k != to_string(val).size() to filter out 010, 00 etc cases
                if (val > 255 || k != to_string(val).size()) continue;
                dfs(s.substr(k), n + 1, out + s.substr(0, k) + (n == 3 ? "" : "."), res);
            }
        }
    }
};
