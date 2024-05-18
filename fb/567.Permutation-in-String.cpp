// Time O(s2.size())
// Space O(1)
class Solution {
private:
    bool matches(const vector<int>& target, const vector<int>& current) {
        for(int i = 0; i < target.size(); i++) {
            if(target[i] != current[i])
                return false;
        }
        return true;
    }
    
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        
        int s1len = s1.size();
        
        vector<int> s1m(26, 0);
        vector<int> s2m(26, 0);
        for(int i = 0; i < s1len; i++) {
            s1m[s1[i] - 'a']++;
            s2m[s2[i] - 'a']++;
        }
        
        for(int i = 0; i < s2.size() - s1len; i++) {
            if(matches(s1m, s2m))
                return true;
            s2m[s2[s1len+i] - 'a']++;
            s2m[s2[i] - 'a']--;
        }
        return matches(s1m, s2m);
    }
};
