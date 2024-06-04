// Time O(NK) - N is the length of strs, and K is the maximum length of a string in strs
// Space O(NK)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> um;
        for(auto s : strs) {
            um[hash(s)].push_back(s);
        }
        for(auto i : um) {
            ans.push_back(i.second);
        }
        return ans;
    }
private:
    string hash(const string& s) {
        vector<int> h(26,0);
        for(int i = 0; i < s.size(); i++) {
            h[s[i] - 'a']++;
        }
        string ans = "";
        for(int i = 0; i < 26; i++) {
            ans += to_string(h[i]) + ","; // avoid hash collision
        }
        return ans;
    }
};
