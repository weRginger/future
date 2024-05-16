// Time O(n)
// Space O(1)
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int num = 0;
        int i = 0, j = 0;
        while(i < word.size() && j < abbr.size()){
            if(abbr[j] >= '0' && abbr[j] <= '9') {
                if(num == 0 && abbr[j] == '0') return false; // leading zeros
                num = num * 10 + abbr[j] - '0';
                j++;
            } else { // abbr j is letter
                if(num > 0) {
                    i += num;
                    num = 0;
                }
                if(word[i] != abbr[j]) return false;
                i++;
                j++;
            }
        }
        if(num > 0) i += num; // abbr ends in num
        return i == word.size() && j == abbr.size();
    }
};
