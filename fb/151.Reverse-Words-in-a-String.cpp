// Time O(n)
// Space O(1)
class Solution {
private:
    void reverse(string &s, int begin, int end) {
        while(begin < end) {
            swap(s[begin++], s[end--]);
        }
    }
public:
    string reverseWords(string &s) {
        int i=0, j=0;
        int start=0;
        int len=s.length();
        int wordcount=0;
        while(true) {
            while(i<len && s[i] == ' ') i++;  // skip spaces in front of the word
            if(i==len) break;
            if(wordcount) s[j++]=' '; // add a space between words if not the first word
            start=j;
            while(i<len && s[i] != ' ') {
                s[j]=s[i];
                j++;
                i++;
            }
            reverse(s,start,j-1); // reverse word in place
            wordcount++;
        }
        s.resize(j); // resize result string
        reverse(s,0,j-1); // reverse whole string
        return s;
    }
};
