class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
        if(haystack.empty() || haystack.size() < needle.size())
            return -1;
        for(int i = 0; i < haystack.size(); i++) {
            int j = 0;
            for(int k = i; j < needle.size(); j++, k++) {
                if(haystack[k] != needle[j])
                    break;
            }
            if(j == needle.size())
                return i;
        }
        return -1;
    }
};