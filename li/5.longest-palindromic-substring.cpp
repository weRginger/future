// O(n^2)
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) {
            return s;
        }
        int ssize = s.size();
        int begin = 0;
        int end = 0;
        for(int i = 0; i < ssize; i++) {
            int j = 0;
            for(; i - j >= 0 && i + j < ssize && s[i-j] == s[i+j]; j++) {}
            j--;
            if(2 * j > end - begin) {
                begin = i - j;
                end = i + j;
            }
            for(j = 0; i - 1 - j >= 0 && i + j < ssize && s[i-1-j] == s[i+j]; j++) {}
            j--;
            if(2 * j + 1 > end - begin) {
                begin = i - 1 - j;
                end = i + j;
            }
        }
        return s.substr(begin, end - begin + 1);
    }
};

// Manacher's O(n)
class Solution {
public:
    string longestPalindrome(string const& s) {
        int sLen = s.length();

        // use the integer 1000 as the "boundary character"
        // the input string can include any ASCII character
        int len = sLen * 2 + 1;
        vector<int> chars(len, 1000);
        for (int i = 0; i < sLen; ++i) chars[2 * i + 1] = s[i];

        int maxLen = 0, resCenter = 0;
        int rightMost = -1, mirror = -1;
        vector<int> radius(len, 0);

        for (int i = 0; i < len; ++i) {
            int r = i < rightMost ? min(radius[mirror * 2 - i], rightMost - i) : 0;
            int left = i - 1 - r, right = i + 1 + r;

            while (right >= 0 && right < len && chars[left] == chars[right]) --left, ++right;
            radius[i] = r = --right - i;

            if (right > rightMost) {
                rightMost = right;
                mirror = i;

                // optimization detail:
                // if right does not exceed rightMost
                // we are sure that r cannot replace maxLen
                if (r > maxLen) {
                    maxLen = r;
                    resCenter = i;
                }
            }
        }

        return s.substr((resCenter - maxLen) / 2, maxLen);
    }
};