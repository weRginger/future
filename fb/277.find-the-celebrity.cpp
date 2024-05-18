// Best solution since the Q asks to minimize calling of knows()
// Time O(n) - Note, in the following code, since we used "map", it costs O(nlogn).
//             To reduce to O(n), we can use "unordered_map" but need to provide 
//             hash func to "pair" as unordered_map does not have default key hash to pair
// Space O(n)
class Solution {
public:
    int findCelebrity(int n) {
        if (n == 0) return -1;
        int c = 0;
        for (int i = 1; i < n; i++) {
            if(!myKnows(i, c)) {
                c = i;
            }
        }
        for (int i = 0; i < n; i++) {
            if (i != c && (myKnows(c, i) || !myKnows(i, c)))
                return -1;
        }
        return c;
    }
private:
    map<pair<int,int>, bool> dict;
    bool myKnows(int a, int b) {
        pair<int, int> p = make_pair(a, b);
        if (dict.find(p) != dict.end()) {
            return dict[p];
        }
        dict[p] = knows(a, b);
        return dict[p];
    }
};

// Time O(n)
// Space O(1)
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
