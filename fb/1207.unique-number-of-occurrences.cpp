// Time O(n)
// Space O(n)
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        for(auto i : arr) {
            if(!freq.count(i)) {
                freq[i] = 1;
            } else {
                freq[i]++;
            }
        }
        unordered_set<int> freqSet;
        for(auto i : freq) {
            if(freqSet.count(i.second)) return false;
            freqSet.insert(i.second);
        }
        return true;
    }
};
