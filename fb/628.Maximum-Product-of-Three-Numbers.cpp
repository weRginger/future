// Time O(n)
// Space O(1)
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int min1 = INT_MAX, min2 = INT_MAX;
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        for(int n: nums) {
            if(n <= min1) {
                min2 = min1;
                min1 = n;
            } else if(n <= min2) {     // n lies between min1 and min2
                min2 = n;
            }
            
            if(n >= max1) {            // n is greater than max1, max2 and max3
                max3 = max2;
                max2 = max1;
                max1 = n;
            } else if(n >= max2) {     // n lies betweeen max1 and max2
                max3 = max2;
                max2 = n;
            } else if(n >= max3) {     // n lies betwen max2 and max3
                max3 = n;
            }
        }
        return max(min1 * min2 * max1, max1 * max2 * max3);
    }
};

// Time O(nlogn)
// Space O(n)
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int S = nums.size();
        sort(nums.begin(), nums.end());
        return max(nums[S-3] * nums[S-2] * nums[S-1],
                   nums[0] * nums[1] * nums[S-1]);
    }
};
