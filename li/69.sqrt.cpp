// source http://www.cnblogs.com/AnnieKim/archive/2013/04/18/3028607.html

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int intSqrt(int x) {
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

    int newtonIntSqrt(int x) {
        if (x == 0) return 0;
        double last = 0;
        double res = 1;
        while (res != last)
        {
            last = res;
            res = (res + x / res) / 2;
        }
        return int(res);
    }

    double newtonDoubleSqrt(double x, double error) {
        if (x == 0) return 0;
        double last = 0.0;
        double res = 1.0;
        while (abs(res - last) > error)
        {
            last = res;
            res = (res + x / res) / 2;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.intSqrt(2147395599) << endl;
    cout << s.newtonIntSqrt(2147395599) << endl;
    cout << s.newtonDoubleSqrt(8.9, 0.01) << endl;
    return 0;
}