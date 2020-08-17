// Time O(n)
// Space O(1)
class Solution {
public:
    bool canConstruct(string s, int k) {
        int S = s.size();
        if(S < k)
            return false;
        unordered_map<char, int> um;
        for(auto c : s) {
            um[c]++;
        }
        int odd = 0;
        for(auto i : um) {
            if(i.second % 2 != 0)
                odd++;
        }
        if(odd <= k) 
            return true;
        return false;
    }
};
