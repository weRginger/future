// Time O(n)
// Space O(1)
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long int first  = LONG_MIN;
        long int second = LONG_MIN;
        long int third  = LONG_MIN;
        for(auto n : nums) {
            if(n >= first) {
                if(n == first) continue;
                third = second;
                second = first;
                first = n;
            } else if(n >= second) {
                if(n == second) continue;
                third = second;
                second = n;
            } else if(n >= third) {
                if(n == third) continue;
                third = n;
            }
        }
        return third != LONG_MIN ? third : max(second, first);
    }
};
