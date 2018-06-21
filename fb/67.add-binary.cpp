class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        if(a.size() < b.size()) {
            swap(a, b);
        }
        int carry = 0;
        int sa = a.size();
        int sb = b.size();
        for(int i = sa - 1, j = sb - 1; i >= 0; i--, j--)  {
            int ia = a[i] - '0';
            int ib = j >= 0 ? b[j] - '0' : 0;
            int num = (ia + ib + carry) % 2;
            carry = (ia + ib + carry) / 2;
            ans = to_string(num) + ans;
        }
        if(carry) {
            ans = to_string(carry) + ans;
        }
        return ans;
    }
};