class Solution {
public:
    bool isPerfectSquare(int num) {
        long l = 1;
        long r = num;
        while(l + 1 < r) {
            long mid = (l + r) >> 1;
            if(mid * mid == num) return true;
            else if(mid * mid > num) r = mid;
            else l = mid;
        }
        if(r * r == num) return r;
        if(l * l == num) return l;
        return false;
    }
};