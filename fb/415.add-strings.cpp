// Time O(max(|num1|, |num2|))
// Space O(max(|num1|, |num2|))
// by ziqi
class Solution {
public:
    string addStrings(string num1, string num2) {
        string sum;
        int sz = num1.size() > num2.size() ? num1.size() : num2.size();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int carry = 0;
        for(int i = 0; i < sz; i++) {
            if(i < num1.size() && i < num2.size()) {
                int n1 = num1[i] - '0';
                int n2 = num2[i] - '0';
                int base = (n1 + n2 + carry) % 10;
                carry = (n1 + n2 + carry) / 10;
                sum.push_back(base + '0');
            } else if(i < num1.size()) {
                int n1 = num1[i] - '0';
                int base = (n1 + carry) % 10;
                carry = (n1 + carry) / 10;
                sum.push_back(base + '0');
            } else {
                int n2 = num2[i] - '0';
                int base = (n2 + carry) % 10;
                carry = (n2 + carry) / 10;
                sum.push_back(base + '0');
            }
        }
        if(carry) {
            sum.push_back(carry + '0');
        }
        reverse(sum.begin(), sum.end());
        return sum;
    }
};

// Time O(max(|num1|, |num2|))
// Space O(max(|num1|, |num2|))
class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.length() < num2.length()) swap(num1, num2);
        num1 = "0" + num1;
        int l1 = num1.length();
        int l2 = num2.length();
        for (int i = 0; i < l1 - 1; ++i) {
            if (i < l2) num1[l1 - i - 1] += (num2[l2 - i - 1] - '0');
            if (num1[l1 - i - 1] > '9') {
                num1[l1 - i - 1] -= 10;
                ++num1[l1 - i - 2];
            }
        }    
        return (num1[0] != '0') ? num1 : num1.substr(1);
    }
};
