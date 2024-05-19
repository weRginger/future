// Time O(n)
// Space O(1) since 26 chars at most
// elegant solution but could use unordered_map as well
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_set<char> us;
        for(auto c : s) {
            if(us.count(c)) {
                us.erase(c);
            } else {
                us.insert(c);
            }
        }
        return us.size() <= 1;
    }
};
