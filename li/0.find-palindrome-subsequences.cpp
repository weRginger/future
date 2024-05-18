#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    unordered_set<string> findPalindromes(string s) {
        unordered_set<string> result;
        int len = s.size();
        if(len < 1) return result;
        if(len == 1) {
            result.insert(s);
            return result;
        }
        if(seqMap.count(s)) {
            return seqMap[s];
        }
        unordered_set<string> set0 = findPalindromes(s.substr(0, len - 1));
        unordered_set<string> set1 = findPalindromes(s.substr(1, len - 1));
        result.insert(set0.begin(), set0.end());
        result.insert(set1.begin(), set1.end());
        if(s[0] == s[len - 1]) {
            unordered_set<string> set2 = findPalindromes(s.substr(1, len - 2));
            string head = s.substr(0,1);
            for(auto i : set2) {
                result.insert(head + i + head);
            }
            result.insert(head + head);
        }
        seqMap[s] = result;
        return result;
    }

private:
    unordered_map<string, unordered_set<string>> seqMap;

};

int main()
{
    Solution s;
    string seq = "abqwerba";
    unordered_set<string> ans = s.findPalindromes(seq);
    cout << "Size of ans " << ans.size() << endl;
    for(auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
