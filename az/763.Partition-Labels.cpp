// Time O(n)
// Space O(1)
class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, int> last;
        for (int i = 0; i < S.size(); ++i)
            last[S[i]] = i;
        int end = 0, start = 0;
        vector<int> ans;
        for (int i = 0; i < S.length(); ++i) {
            end = max(end, last[S[i]]);
            if (i == end) {
                ans.push_back(i - start + 1);
                start = i + 1;
            }
        }
        return ans;
    }
};
