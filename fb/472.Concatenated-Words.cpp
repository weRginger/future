
// recursion
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        unordered_set<string> dict(words.begin(), words.end());
        for (string word : words) {
            if (word.empty()) continue;
            if (helper(word, dict, 0, 0)) {
                res.push_back(word);
            }
        }
        return res;
    }
    bool helper(string& word, unordered_set<string>& dict, int pos, int cnt) {
        if (pos >= word.size() && cnt >= 2) return true;
        for (int i = 1; i <= (int)word.size() - pos; ++i) {
            string t = word.substr(pos, i);
            if (dict.count(t) && helper(word, dict, pos + i, cnt + 1)) {
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& 
    ) {
        if (words.size() <= 2) return {};
        vector<string> res;
        unordered_set<string> dict(words.begin(), words.end());
        for (string word : words) {
            dict.erase(word); // remove to make sure at least need 2 words to form an answer
            int len = word.size();
            if (len == 0) continue;
            vector<bool> v(len + 1, false);
            v[0] = true;
            for (int i = 0; i < len + 1; ++i) {
                for (int j = 0; j < i; ++j) {
                    if (v[j] && dict.count(word.substr(j, i - j))) {
                        v[i] = true;
                        break;
                    }
                }
            }
            if (v.back()) res.push_back(word);
            dict.insert(word);
        }
        return res;
    }
};
