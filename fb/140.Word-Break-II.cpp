// Time O(2^n)
// Space O(2^n)
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());
        return wordBreak(s, dict);
    }
    
private:
    vector<string> append(const string& word, const vector<string>& suffixes) {
        vector<string> results;
        for(const auto& suffix : suffixes)
            results.push_back(word + " " + suffix);
        return results;
    }
    
    const vector<string>& wordBreak(string s, unordered_set<string>& dict) {
        if(mem_.count(s)) return mem_[s];
        
        vector<string> ans;
        
        
        // s in dict, add it to the answer array
        // so we can avoid adding non-needed space when calling append() 
        if(dict.count(s)) 
            ans.push_back(s);
        
        for(int j = 1; j < s.length(); ++j) {
            // Check whether left part is a word
            const string& left = s.substr(0, j);
            if (!dict.count(left)) continue;
            
            // Get the ans for right part
            const string& right = s.substr(j);
            const vector<string> right_ans = 
                append(left, wordBreak(right, dict));
            
            // Notice, can not use mem_ here,
            // since we haven't got the ans for s yet.
            ans.insert(ans.end(), right_ans.begin(), right_ans.end());
        }
        
        // memorize and return
        return mem_[s] = ans;
    }

    unordered_map<string, vector<string>> mem_;
};
