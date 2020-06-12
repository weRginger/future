class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size()-1;
        int n2 = num2.size()-1;
        string result = "";
        int carry = 0;
        while(n1>=0 || n2>=0){
            int sum = 0;
            if(n1>=0){
                sum += num1[n1]-'0';
            }
            if(n2>=0){
                sum += num2[n2]-'0';
            }
            sum+=carry;
            if(sum>=10){
                carry=1;    
                sum=sum%10;
            }else{
                carry=0;
            }
            result=to_string(sum)+result;
            n1--;
            n2--;
        }
        if(carry==1){
            result=to_string(carry)+result;
        }
        return result;
    }
};
