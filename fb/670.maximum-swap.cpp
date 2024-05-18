// Time O(n)
// Space O(n)
class Solution {
public:
    int maximumSwap(int num) {
        string digits = to_string(num);

        vector<int> buckets(10);
        for (int i = 0; i < digits.size(); i++) {
            buckets[digits[i] - '0'] = i;
        }

        for (int i = 0; i < digits.size(); i++) {      //从最高位开始
            for (int k = 9; k > digits[i] - '0'; k--) {    // k需要比数字digits[i]大
                if (buckets[k] > i) {     //如果k的位置在i后面
                    swap(digits[buckets[k]], digits[i]);
                    return stoi(digits);
                }
            }
        }

        return num;
    }
};
