// Time O(n)
// Space O(1)
class Solution {
public:
    int titleToNumber(string s) {
        long base = 1;
        int total = 0;
        for(int i = s.size() - 1; i >= 0; i--) {
            total += base * (s[i] - 'A' + 1);
            base *= 26;
        }
        return total;
    }
};

// using pow
class Solution {
public:
    int titleToNumber(string s) {
        int total = 0;
        for(int i=s.length()-1, k=0; i >= 0; i--, k++){
            total += (s[i] -'A' + 1) * pow(26,k); 
        }
        return total;
    }
};
