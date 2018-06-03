// This solution is explained in lc 191. Number of 1 Bits
class Solution {
public:
    int hammingDistance(int x, int y) {
        int _xor = x ^ y;
        int ans = 0;
        while(_xor != 0) {
            ans++;
            // set the least significant 1 to 0
            _xor &= _xor - 1;
        }
        return ans;
    }
};

class Solution {
public:
    int hammingDistance(int x, int y) {
        int _xor = x ^ y;
        int ans = 0;
        while(_xor > 0) {
            if(_xor & 1) ans++;
            _xor >>= 1;
        }
        return ans;
    }
};