// Time O(n)
// Space O(1)
class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        if(!buf || n <= 0) return 0;
        int ans = 0;
        while(n > 0) {
            int out = read4(buf + ans);
            if(out == 0) break;
            out = min(n, out);
            n -= out;
            ans += out;
        }
        return ans;
    }
};

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int len = 0;
        char buf4[4];
        while(len < n) {
            int ret = read4(buf4);
            if(ret == 0) 
                return len;
            for(int i = 0; i < ret; i++) {
                buf[len++] = buf4[i];
                if(len == n)
                    return len;
            }
        }
        return len;
    }
};
