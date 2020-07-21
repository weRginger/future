// Time O(|nums1| + |num2|)
// Space O(|num2|)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        unordered_map<int, int> um;
        for(int i = 0; i < nums2.size(); i++) {
            while(!stk.empty() && nums2[i] > stk.top()) {
                um[stk.top()] = nums2[i];
                stk.pop();
            }
            stk.push(nums2[i]);
        }
        while(!stk.empty()) {
            um[stk.top()] = -1;
            stk.pop();
        }
        
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(um[nums1[i]]);
        }
        
        return ans;
    }
};
