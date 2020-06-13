// Time O(n)
// Space O(n)
// By Ziqi
// dp[i] denotes the index of largest number on the right of i - including i.
// The idea is starting from the leftmost digit i, if the largest one on its right (stored in dp[i+1]) 
// is larger than digit i, swap them will give us the largest num
class Solution {
public:
    int maximumSwap(int num) {
        string c = to_string(num);
        int n = c.size();
        vector<int> dp(n, n - 1);
        char max = c[n-1];
        for(int i = n - 2; i >= 0; i--){
            // note: here must be ">" not ">=" since if there is duplicate digit, we want the rightmost
            if(c[i] > max) {
                max = c[i];
                dp[i] = i;
            } else {
                dp[i] = dp[i+1];
            }
        }
        for(int i = 0; i < n - 1; i++) {
            if(c[i] < c[dp[i+1]]) {
                swap(c[i], c[dp[i+1]]);
                return stoi(c);
            }
        }
        return num;
    }
};
