// Time O(log16(N))
// Space O(1)
class Solution {
public:
    string toHex(int num) {
        if(num==0) return to_string(0);
 
        long n=num;
        
        if(n<0)
            n=pow(2,32)-abs(n);
        
        vector<char> v={'0','1','2','3','4','5','6','7',
                        '8','9','a','b','c','d','e','f'};
        
        string s="";
        while(n>0) {
            s = s + v[n % 16];
            n = n / 16;
        }
        
        reverse(s.begin(), s.end());
        return s;
    }
};
