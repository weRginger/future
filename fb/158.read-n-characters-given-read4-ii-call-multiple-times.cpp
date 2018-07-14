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
        int len = 0; // len is the length of the read characters
        while (len < n) {
            while (i < p && len < n) { // load the remaining in cache
                buf[len++] = cache[i++];
            }
            if (len == n)
                return len;
            p = read4(cache);
            if (p == 0)
                return len;
            i = 0;
        }
        return len;
    }
private:
    char cache[4];
    int i = 4; // index
    int p = 4; // valid number of characters in cache
};