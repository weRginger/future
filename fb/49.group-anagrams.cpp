// Time: O(n*k*logk)
// Space: O(n*k)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        if(strs.empty()) return ans;
        unordered_map<string, vector<string>> mp;
        for(auto s : strs) {
            string cur = s;
            sort(s.begin(),s.end());
            mp[s].push_back(cur);
        }
        for(auto e : mp) {
            ans.push_back(e.second);
        }
        return ans;
    }
};

// Time: O(n*k)
// Space: O(n*k)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for (string str : strs) {
            vector<int> cnt(26, 0);
            string t = "";
            for (char c : str) ++cnt[c - 'a'];
            for (int d : cnt) t += to_string(d) + "/";
            m[t].push_back(str);
        }
        for (auto a : m) {
            res.push_back(a.second);
        }
        return res;
    }
};