// Time O(n)
// Space O(1)
class Solution {
private:
    bool isVowel(char c){
        return (c=='a'||
                c=='e'||
                c=='o'||
                c=='i'||
                c=='u'||
                c=='A'||
                c=='E'||
                c=='O'||
                c=='I'||
                c=='U');
    }
public:
    string reverseVowels(string s) {
        int len=s.length();
        for (int i=0,j=len-1;i<j;){
            if(isVowel(s[i])&&isVowel(s[j])){swap(s[i],s[j]);i++,j--;}
            if(!isVowel(s[i])){i++;}
            if(!isVowel(s[j])){j--;}
        }
        return s;
    }
};
