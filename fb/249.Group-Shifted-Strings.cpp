// Time O(n*l), where n is |strings| and l is length of each string
// Space O(n)
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string> > res;
        unordered_map<string, vector<string>> m;
        for (auto a : strings) {
            string hash = "";
            for (char c : a) {
                // must have this "," or could have hash collision
                hash += to_string((c + 26 - a[0]) % 26) + ","; 
            }
            m[hash].push_back(a);
        }
        for (auto item : m) {
            res.push_back(item.second);
        }
        return res;
    }
};
