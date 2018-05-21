class Solution {
public:
    int mySqrt(int x) {
        long long l = 1;
        long long r = x;
        while (l + 1 < r)
        {
            long long mid = (l + r) / 2;
            long long sq = mid * mid;
            if (sq == x) return mid;
            else if (sq < x) l = mid;
            else r = mid;
        }
        long long sq = r * r;
        if(sq <= x) return r;
        return l;
    }
};