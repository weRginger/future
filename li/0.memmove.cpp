class Solution {
public:
    void *memmove(void *dest, void *src, size_t n) {
        char *d = static_cast<char *>(dest);
        const char *s = static_cast<const char *>(src);

        if(s > d) {
            while(n-- != 0) {
                *d++ = *s++;
            }
        }
        else {
            d += n;
            s += n;
            while(n-- != 0) {
                *d-- = *s--;
            }
        }

        return dest;
    }
};