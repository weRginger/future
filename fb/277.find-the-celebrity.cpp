// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        if(n == 0) return -1;
        int c = 0;
        for(int i = 1; i < n; i++) {
            if(knows(i, c)) {
                continue;
            }
            else {
                c = i;
            }
        }
        for(int i = 0; i < n; i++) {
            if(i != c && (knows(c, i) || !knows(i, c)))
                return -1;
        }
        return c;
    }
};
