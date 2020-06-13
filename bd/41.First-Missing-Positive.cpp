class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // if nums does not contain 1, return 1
        int contains = 0;
        for(int i = 0; i < n; i++)
          if(nums[i] == 1) {
            contains++;
            break;
          }
        if(contains == 0)
          return 1;

        // Replace negative numbers, zeros,
        // and numbers larger than n by 1s.
        // After this convertion nums will contain 
        // only positive numbers.
        for(int i = 0; i < n; i++) {
            if((nums[i] <= 0) || (nums[i] > n)) nums[i] = 1;
        }

        // Use index as a hash key and number sign as a presence detector.
        // For example, if nums[0] is negative that means that number `1`
        // is present in the array. 
        // If nums[1] is positive - number 2 is missing.
        for (int i = 0; i < n; i++) {
            int a = abs(nums[i]);
            nums[a - 1] = - abs(nums[a - 1]);
        }

        // Now the index of the first positive number 
        // is equal to first missing positive.
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) return i + 1;
        }

        return n + 1;
    }
};
