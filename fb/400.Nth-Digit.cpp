class Solution {
public:
    int findNthDigit(int n) {
        if (n < 10){
            return n;
        }
        int len = 0;//单个数字的长度
        
        //长度为len + 1的数字所构成的字符串的长度
        long long nextSize = pow(10, len) * (len + 1) * 9;
        
        //第一步：确定n所处的数字的位数
        while (n > nextSize){
            n -= nextSize;
            len += 1;
            
            //长度为len + 1的数字所构成的字符串的长度
            nextSize = pow(10, len) * (len + 1) * 9;
        }
        
        //第二步：确定n是出于位数为len + 1的数字中的第几个数字，并且转换为字符串
        string resStr = to_string((long long)pow(10, len) + (n - 1) / (len + 1));
        //返回n在这个数字中对应的位，（比如当n == 15，求得len = 1，n = 6， resStr = “12”,然后取出“12”字符串的第二位）
        //注意返回的int数字，并不是返回字符'k',需要减去'0'
        return resStr[n - (n - 1) / (len + 1) * (len + 1) - 1] - '0';
    }
};
