// Time O(ss + ps)
// Space O(1)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ss = s.size();
        int ps = p.size();
        vector<int> ans;
        if(ss == 0 || ps == 0 || ss < ps)
            return ans;
        vector<int> sm(26, 0);
        vector<int> pm(26, 0);
        for(int i = 0; i < ps; i++) {
            sm[s[i] - 'a']++;
            pm[p[i] - 'a']++;
        }
        if(sm == pm)
            ans.push_back(0);
        for(int i = ps; i < ss; i++) {
            sm[s[i] - 'a']++;
            sm[s[i - ps] - 'a']--;
            if(sm == pm)
                ans.push_back(i - ps + 1);
        }
        return ans;
    }
};
