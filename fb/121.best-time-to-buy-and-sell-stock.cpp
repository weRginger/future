// Time O(n)
// Space O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int ans = 0;
        for(int i = 1, min = prices[0]; i < prices.size(); i++) {
            if(prices[i] < min) {
                min = prices[i];
            }
            else {
                ans = max(ans, prices[i] - min);
            }
        }
        return ans;
    }
};
