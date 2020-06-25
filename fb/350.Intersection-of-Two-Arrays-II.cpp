// Time O(m+n)
// Space O(min(m,n))
class Approach1 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return intersect(nums2, nums1);
        }
        vector<int> ans;
        unordered_map<int, int> m;
        for (auto n : nums1) {
            ++m[n];
        }
        for (auto n : nums2) {
            auto it = m.find(n);
            if (it != end(m) && --it->second >= 0) {
                ans.push_back(n);
            }
        }
        return ans;
    }
};

// Time O(mlogm+nlogn)
// Space O(1)
class Approach2 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));
        vector<int> ans;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                ++i;
            } else if (nums1[i] > nums2[j]) {
                ++j;
            } else {
                ans.push_back(nums1[i]);
                ++i;
                ++j;
            }
        }
        return ans;
    }
};

/*
Follow-up Questions

Q: What if the given array is already sorted? How would you optimize your algorithm?
A: We can use either Approach2, dropping the sort of course. It will 
give us linear time and constant memory complexity.

Q: What if nums1's size is small compared to nums2's size? Which algorithm is better?
A: Approach1 is a good choice here as we use a hash map for the smaller array.

Q: What if elements of nums2 are stored on disk, and the memory is limited such that you 
cannot load all elements into the memory at once?
A: If nums1 fits into the memory, we can use Approach1 to collect counts for nums1 into a
hash map. Then, we can sequentially load and process nums2. If neither of the arrays fit into 
the memory, we can apply some partial processing strategies:
  - Split the numeric range into subranges that fits into the memory. Modify Approach1 to 
    collect counts only within a given subrange, and call the method multiple times (for each subrange).
  - Use an external sort for both arrays. Modify Approach 2 to load and process arrays sequentially.
*/
