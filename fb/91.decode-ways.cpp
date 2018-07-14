class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        if (s.length() == 1) return 1;

        const int n = s.length();
        int w1 = 1;
        int w2 = 1;
        for (int i = 1; i < n; ++i) {
            int w = 0;
            if (!isValid(s[i]) && !isValid(s[i - 1], s[i])) return 0;
            if (isValid(s[i])) w = w1;
            if (isValid(s[i - 1], s[i])) w += w2;
            w2 = w1;
            w1 = w;
        }
        return w1;
    }
private:
    bool isValid(const char c) {
        return c != '0';
    }
    bool isValid(const char c1, const char c2) {
        const int num = (c1 - '0')*10 + (c2 - '0');
        return num >= 10 && num <= 26;
    }
};