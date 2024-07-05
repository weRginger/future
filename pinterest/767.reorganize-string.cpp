// Time O(N)
// Space O(1)
class Solution {
public:
    string reorganizeString(string s) {
        vector<int> charCounts(26, 0);
        for (char c : s) {
            charCounts[c - 'a']++;
        }
        int maxCount = 0, letter = 0;
        for (int i = 0; i < charCounts.size(); i++) {
            if (charCounts[i] > maxCount) {
                maxCount = charCounts[i];
                letter = i;
            }
        }
        if (maxCount > (s.length() + 1) / 2) {
            return "";
        }
        string ans = s;
        int index = 0;

        // Place the most frequent letter
        while (charCounts[letter] != 0) {
            ans[index] = char(letter + 'a');
            index += 2;
            charCounts[letter]--;
        }

        // Place rest of the letters in any order
        for (int i = 0; i < charCounts.size(); i++) {
            while (charCounts[i] > 0) {
                if (index >= s.length()) {
                    index = 1;
                }
                ans[index] = char(i + 'a');
                index += 2;
                charCounts[i]--;
            }
        }

        return ans;
    }
};

// Time O(N⋅logk)
// Space O(1)
class Solution {
public:
    string reorganizeString(string s) {
        vector<int> charCounts(26, 0);
        for (char c : s) {
            charCounts[c - 'a']++;
        }

        // Max heap ordered by character counts
        priority_queue<vector<int>> pq;
        for (int i = 0; i < 26; i++) {
            if (charCounts[i] > 0) {
                pq.push(vector<int>{charCounts[i], i + 'a'});
            }
        }
        
        string result;
        while (!pq.empty()) {
            auto first = pq.top();
            pq.pop();
            if (result.empty() || first[1] != result.back()) {
                result += char(first[1]);
                if (--first[0] > 0) {
                    pq.push(first);
                }
            } else {
                if (pq.empty()) {
                    return "";
                }
                auto second = pq.top();
                pq.pop();
                result += char(second[1]);
                if (--second[0] > 0) {
                    pq.push(second);
                }
                pq.push(first);
            }
        }

        return result;
    }
};
