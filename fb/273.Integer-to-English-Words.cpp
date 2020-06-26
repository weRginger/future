// Time O(n)
// Space O(1)
class Solution {
    vector<string> mOneDigitNumberTotext = {"", "One", "Two", "Three",
                                            "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> mTensInText = {"", "Ten", "Twenty", "Thirty", 
                                  "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    string TwoDigitNumberToText (int n) {
        string result = "";
        if(n > 19) {
            result += mTensInText[n/10];
            if(n % 10 > 0) {
                result += " " + mOneDigitNumberTotext[n%10];
            }
            return result;
        } else {
            switch (n) {
                case 11:
                    return "Eleven";
                case 12:
                    return "Twelve";
                case 13:
                    return "Thirteen";
                case 14:
                    return "Fourteen";
                case 15:
                    return "Fifteen";
                case 16:
                    return "Sixteen";
                case 17:
                    return "Seventeen";
                case 18:
                    return "Eighteen";
                case 19:
                    return "Nineteen";
                default:
                    return mTensInText[n/10];
            }
        }
    }

    string ThreeDigitNumberToText (int n) {
        int d0 = n/100; // 100's palce
        int d1 = (n%100)/10; // ten's place
        int d2 = n%100; // one's place
        string result = "";
        if (d0 > 0) result += mOneDigitNumberTotext[d0] + " Hundred ";
        if (d1 > 0)
            result += TwoDigitNumberToText(n%100);
        else 
            result += mOneDigitNumberTotext[d2];
        if (result[result.length()-1] == ' ') return result.substr(0, result.length()-1);
        return result;
    }
    
public:
    string numberToWords(int n) {
        if (n == 0) return "Zero"; // handle zero case
        int d0 = n/1000000000; // billion's digits
        int d1 = (n%1000000000)/1000000; // million's digits
        int d2 = (n%1000000)/1000; // thousand's digits
        int d3 = (n%1000);  // hundred's digits
        string result = "";
        if (d0 > 0) result += ThreeDigitNumberToText(d0) + " Billion ";
        if (d1 > 0) result += ThreeDigitNumberToText(d1) + " Million ";
        if (d2 > 0) result += ThreeDigitNumberToText(d2) + " Thousand ";
        if (d3 > 0) result += ThreeDigitNumberToText(d3);
        if (result[result.size()-1] == ' ') return result.substr(0, result.length()-1);
        return result;
    }
};
