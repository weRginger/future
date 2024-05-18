// Time O(n)
// Space O(1)
class Solution {
public:
    int compress(vector<char>& chars) {
        const int n = chars.size();
        int p = 0;
        for (int i = 1; i <= n; ++i) {
            int count = 1;
            while (i < n && chars[i] == chars[i - 1]) { 
                ++i; ++count;
            }
            chars[p++] = chars[i - 1];
            if (count == 1) 
                continue;
            for (char c : to_string(count))
                chars[p++] = c;
        }
        return p;
    }
};
