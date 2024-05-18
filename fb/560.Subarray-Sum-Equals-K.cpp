// Source: https://www.geeksforgeeks.org/number-subarrays-sum-exactly-equal-k/
// Time O(n)
// Space O(n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.empty()) return 0;
        
        // STL map to store number of subarrays 
        // starting from index zero having  
        // particular value of sum. 
        unordered_map<int, int> prevSum; 

        int res = 0; 

        // Sum of elements so far. 
        int currsum = 0;
        
        for (int i = 0; i < nums.size(); i++) { 
            // Add current element to sum so far. 
            currsum += nums[i]; 

            // If currsum is equal to desired sum, 
            // then a new subarray is found. So 
            // increase count of subarrays. 
            if (currsum == k)  
                res++;         

            // currsum exceeds given sum by (currsum - sum). 
            // Find number of subarrays having this sum and exclude those
            // subarrays from currsum by increasing count by same amount. 
            if (prevSum.find(currsum - k) !=  prevSum.end())  
                res += (prevSum[currsum - k]); 

            // Add currsum value to count of  
            // different values of sum. 
            prevSum[currsum]++; 
        } 
        return res; 
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

