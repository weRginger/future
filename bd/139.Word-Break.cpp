class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto word : wordDict) {
            ws.insert(word);
        }
        return helper(s);
    }
private:
    unordered_map<string, bool> mem;
    unordered_set<string> ws;
    
    bool helper(string s) {
        if(mem.find(s) != mem.end()) return mem[s];
        if(s.empty()) return true;
        for(int i = 1; i <= s.size(); i++) {
            string tmp = s.substr(0, i);
            if(ws.find(tmp) != ws.end()) {
                if(helper(s.substr(i))) {
                    mem[s.substr(i)] = true;
                    return true;
                }
            }
        }
        mem[s] = false;
        return false;
    }
};
