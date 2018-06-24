// Forward declaration of the read4 API.
int read4(char *buf);

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