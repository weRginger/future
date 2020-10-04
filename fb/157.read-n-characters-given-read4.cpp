// Time O(n)
// Space O(1)
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
