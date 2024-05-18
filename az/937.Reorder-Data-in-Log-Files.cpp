// Time: O(n(logn))
// Space: O(n)
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> res, digitLogs;
        vector<idLetters> letterLogs;
        for (string log : logs) {
            auto pos = log.find(" ");
            if (log[pos + 1] >= '0' && log[pos + 1] <= '9') {
                digitLogs.push_back(log);
            }
            else 
                letterLogs.push_back({log.substr(0, pos), log.substr(pos + 1)});
        }
        sort(letterLogs.begin(), letterLogs.end(), [](idLetters& a, idLetters& b) {
            return a.second < b.second || (a.second == b.second && a.first < b.first);
        });
        for (auto &a : letterLogs) {
            res.push_back(a.first + " " + a.second);
        }
        for (string log : digitLogs) res.push_back(log);
        return res;
    }
private:
    typedef pair<string, string> idLetters;
};
