// Time O(m+n)
// Space O(m+n)
class Solution {
private:
    vector<int> set_intersection(const unordered_set<int>& set1, 
                                 const unordered_set<int>& set2) {
        vector<int> ret;
        for(auto s : set1)
          if (set2.find(s) != set2.end()) 
              ret.push_back(s);
        return ret;
    }
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1;
        for (auto n : nums1) set1.insert(n);
        unordered_set<int> set2;
        for (auto n : nums2) set2.insert(n);
        
        if (set1.size() < set2.size()) 
            return set_intersection(set1, set2);
        return set_intersection(set2, set1);
    }
};
