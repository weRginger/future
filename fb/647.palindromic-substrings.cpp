class Solution {
public:
    int countSubstrings(string s) {
        /*
         * The idea is count the number of different palindromic substrings from their respective middle.
         * In the following code, when we consider the substring s[i-j, ..., i+j], i is the middle index of the substring;
         * When we consider the substring s[i-1-j, ..., i+j], (i-1, i) is the middle index of the substring.
         */
        int res = 0, n = s.length();
        for(int i = 0; i < n; i++) {
            for(int j = 0; i-j >= 0 && i+j < n && s[i-j] == s[i+j]; j++)res++; //substring s[i-j, ..., i+j]
            for(int j = 0; i-1-j >= 0 && i+j < n && s[i-1-j] == s[i+j]; j++)res++; //substring s[i-1-j, ..., i+j]
        }
        return res;
    }
};
