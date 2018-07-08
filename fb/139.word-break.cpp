class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.empty()) return false;
        if(s.empty()) return true;
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<int, bool> memo;
        return word_Break(s, wordSet, 0, memo);
    }
private:
    bool word_Break(string& s, unordered_set<string>& wordSet, int start, unordered_map<int, bool>& memo) {
        if (start == s.size()) {
            return true;
        }
        if (memo.count(start)) {
            return memo[start];
        }
        for (int end = start; end < s.size(); end++) {
            if (wordSet.count(s.substr(start, end - start + 1)) && word_Break(s, wordSet, end + 1, memo)) {
                return memo[start] = true;
            }
        }
        return memo[start] = false;
    }
};