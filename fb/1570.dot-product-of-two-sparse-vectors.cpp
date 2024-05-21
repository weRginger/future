// Let n be the length of the input array and L be the number of smaller vector's non-zero elements.
// Time: O(n) for creating the Hash Map; O(L) for calculating the dot product.
// Space: O(L) for creating the Hash Map. O(1) for calculating the dot product.
class SparseVector {
    unordered_map<int, int> um;
public:
    
    SparseVector(vector<int> &nums) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i]) um[i] = nums[i];
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int ans = 0;
        // iterate over smaller um for further optimization
        // also answer the follow up q about if only one is a sparse
        unordered_map<int, int>& smaller_um = um.size() < vec.um.size() ? um : vec.um;
        unordered_map<int, int>& largger_um = um.size() >= vec.um.size() ? um : vec.um;
        for(auto item: smaller_um) {
            int key = item.first;
            if(largger_um.count(key)) {
                ans += item.second * largger_um[key];
            }
        }
        return ans;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
