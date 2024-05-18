// Time O(n!)
// Space O(n)
// Author: Ziqi
// If can form palindromes, permute only half of it and append reverse to it to form the final palindrome
class Solution {
public:
    vector<string> generatePalindromes(string s) {
        unordered_map<char, int> um;
        for(auto c : s) {
            um[c]++;
        }
        
        int odd = 0;
        unordered_map<char, int> perm;
        string single = "";
        for(auto i : um) {
            if(i.second % 2 != 0) {
                odd++;
                single = i.first;
                if(i.second / 2 > 0)
                    perm[i.first] = i.second / 2;
            } else {
                perm[i.first] = i.second / 2;
            }
        }
        if(odd > 1) return {};
        
        vector<string> ans;
        string curr = "";
        helper(perm, curr, s.size() / 2, ans, single);
        return ans;
        
    }
private:
    void helper(unordered_map<char, int>& perm, string& curr, int count, vector<string>& ans, string single) {
        if(curr.size() >= count) {
            ans.push_back(curr + single + string(curr.rbegin(),curr.rend()));
            return;
        }
        for(auto& i : perm) {
            if(i.second > 0) {
                curr.push_back(i.first);
                i.second--;
                helper(perm, curr, count, ans, single);
                i.second++;
                curr.pop_back();
            }
        }
    }
};
