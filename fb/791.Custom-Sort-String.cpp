// Time O(S+T)
// Space O(1)
class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> count(26, 0);
        for (char c: T)
            count[c - 'a']++;

        string ans = "";

        // Write all characters that occur in S, in the order of S.
        for (char c: S) {
            for (int i = 0; i < count[c - 'a']; ++i)
                ans += c;
            // Setting count[char] to zero to denote that we do
            // not need to write 'char' into our answer anymore.
            count[c - 'a'] = 0;
        }

        // Write all remaining characters that don't occur in S.
        // That information is specified by 'count'.
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < count[i]; ++j)
                ans += 'a' + i;

        return ans;
    }
};
