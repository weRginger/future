// Time O(C), where C is total chars in words
// Space O(1)
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> um;
        for(int i = 0; i < order.size(); i++) {
            um[order[i]] = i;
        }
        
        for(int i = 1; i < words.size(); i++) {
            int s0 = words[i-1].size();
            int s1 = words[i].size();
            int j = 0;
            while(j < s0 && j < s1) {
                if(words[i-1][j] != words[i][j]) {
                    if(um[words[i-1][j]] >= um[words[i][j]])
                        return false;
                    break;
                }
                j++;
            }
            if(j < s0 && j == s1)
                return false;
        }
        return true;
    }
};
