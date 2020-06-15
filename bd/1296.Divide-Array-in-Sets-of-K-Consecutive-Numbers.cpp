// Time O(n(logn)) since map is ordered and takes logn for each put/get
// Space O(n)
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size() % k) return false;
        map<int, int> m;
        for(auto num : nums) {
            if(m.find(num) == m.end()) {
                m[num] = 1;
            } else {
                m[num]++;
            }
        }
        while(!m.empty()) {
            int key = m.begin()->first;
            for(int i = key; i < key + k; i++) {
                if(m[i] <= 0) return false;
                m[i]--;
                if(m[i] == 0) m.erase(i);
            }
        }
        return true;
    }
};
