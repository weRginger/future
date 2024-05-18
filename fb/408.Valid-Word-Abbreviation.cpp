// Time O(n)
// Space O(1)
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        if (word.empty() || abbr.empty()) return false;

        int i = 0; int j = 0, number = 0;
        while (i < word.size() && j < abbr.size()) {
            if (abbr[j] >= '0' && abbr[j] <= '9') {
                number = number * 10 + abbr[j] - '0';
                if(number == 0) 
                    return false;
                j++;
            } else {
                i += number;
                number = 0;
                if(i >= word.size() || word[i] != abbr[j]) 
                    return false;
                i++;
                j++;
            }
        }
        i += number;
        return i == word.size() && j == abbr.size();
    }
};
