// Time O(|t| + |s|), where |t| to construct the vector and 2*|s| to move start and end
// Space O(1)
// author ziqi
class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        if(m < n) return "";

        unordered_map<char, int> char_count;
        for(auto c : t) {
            char_count[c]++;
        }

        int min_len = INT_MAX, count = 0, min_start_idx = -1;
        for(int start = 0, end = 0; end < m; end++) {
            if(char_count.count(s[end])) {
                if(char_count[s[end]] > 0) {
                    count++;
                } 
            }
            char_count[s[end]]--;
            while(count == n) {
                if(end - start < min_len) {
                    min_start_idx = start;
                    min_len = end - start;
                }
                if(char_count[s[start]] >= 0) {
                    count--;
                }
                char_count[s[start]]++;
                start++;
            }
        }

        if(min_start_idx != -1) {
            return s.substr(min_start_idx, min_len + 1);
        }
        return "";
    }
};

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> m(128, 0);
        // Statistic for count of char in t
        for (auto c : t) m[c]++;
        // counter represents the number of chars of t to be found in s.
        size_t start = 0, end = 0, counter = t.size(), minStart = 0, minLen = INT_MAX;
        size_t size = s.size();

        // Move end to find a valid window.
        while (end < size) {
            // If char in s exists in t, decrease counter
            if (m[s[end]] > 0)
                counter--;
            // Decrease m[s[end]]. If char does not exist in t, m[s[end]] will be negative.
            m[s[end]]--;
            end++; // NOTE: end++ here, so minLen in line 75 does not need to use minLen + 1, which is diff from ziqi's answer in line 37
            // When we found a valid window, move start to find smaller window.
            while (counter == 0) {
                if (end - start < minLen) {
                    minStart = start;
                    minLen = end - start;
                }
                m[s[start]]++;
                // When char exists in t, increase counter.
                if (m[s[start]] > 0)
                    counter++;
                start++;
            }
        }
        if (minLen != INT_MAX)
            return s.substr(minStart, minLen);
        return "";
    }
};
