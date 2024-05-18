class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> ans;
        if(s.length() < 10) return vector<string>();
        unordered_set<string> m;
        for(int i = 0; i < s.length() - 9; i++) {
            if(!m.count(s.substr(i,10))) {
                m.insert(s.substr(i,10));
            }
            else {
                ans.insert(s.substr(i,10));
            }
        }
        return vector<string>(ans.begin(), ans.end());
    }
};

// bit encoding
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if(s.size() < 10)
            return res;
        unordered_map<int, int> DNA;
        unordered_map<char, int> types;
        types['A'] = 0;
        types['C'] = 1;
        types['G'] = 2;
        types['T'] = 3;
        int key = 0;
        for(int i = 0; i<s.size(); i++) {
            key = ((key << 2) | types[s[i]]) & 0xfffff;
            if(i < 9)
                continue;
            if(DNA.find(key) == DNA.end())
                DNA[key] = 1;
            else if(DNA[key] == 1) {
                DNA[key] = 2;
                res.push_back(s.substr(i-9, 10));
            }
        }
        return res;
    }
};
