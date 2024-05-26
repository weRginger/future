// Source: https://www.geeksforgeeks.org/number-subarrays-sum-exactly-equal-k/
// Time O(n)
// Space O(n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, sum = 0;
        unordered_map<int, int> um;
        um[0] = 1; // dealing with acceptable subarray starting from index 0
        for(auto i : nums) {
            sum += i;
            if(um.count(sum-k)) {
                ans += um[sum-k];
            }
            um[sum]++; // only add by 1 after update ans
        }
        return ans;
    }
};

// Time O(n^2) - exceed time limit
// Space O(1)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       int count = 0;
        for (int start = 0; start < nums.size(); start++) {
            int sum=0;
            for (int end = start; end < nums.size(); end++) {
                sum+=nums[end];
                if (sum == k)
                    count++;
            }
        }
        return count; 
    }
};

