// Time O(logn)
// Space O(1)
class Solution {
public:
    double myPow(double x, int n) {
        long N = n;
        if(N < 0) {
            x = 1 / x;
            N = -N;
        }
        double ans = 1;
        double current_product = x;
        while(N) {
            if(N & 1) 
                ans = ans * current_product;
            current_product = current_product * current_product;
            N >>= 1;
        }
        return ans;
    }
};
