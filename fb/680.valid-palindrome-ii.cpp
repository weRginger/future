// Time: O(n)
// Space: O(1)
class Solution {
public:
    bool validPalindrome(string s) {
        int i=0,j=s.size()-1;
        while (i<j && s[i] == s[j]) {
            i++;
            j--;
        };
        int i1=i+1, j1=j, i2=i, j2=j-1;
        while (i1<j1 && s[i1] == s[j1]) {
            i1++;
            j1--;
        };
        while (i2<j2 && s[i2] == s[j2]) {
            i2++;
            j2--;
        };
        return i>=j || i1>=j1 || i2>=j2;
    }
};

class Solution {
private:
    bool isPalindrome(const string& s, int i, int j) {
        for (int k = i; k <= i + (j - i) / 2; k++) {
            if (s[k] != s[j - k + i]) 
                return false;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int ssize = s.size();
        for (int i = 0; i < ssize / 2; i++) {
            if (s[i] != s[ssize - 1 - i]) {
                int j = ssize - 1 - i;
                return (isPalindrome(s, i+1, j) ||
                        isPalindrome(s, i, j-1));
            }
        }
        return true;
    }
};
